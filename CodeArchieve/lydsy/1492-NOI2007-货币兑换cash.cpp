#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using std::max;
const int N = 1e6 + 10;
const double EPS = 1e-7;
int n, sk[N];
double f[N], s, a[N], b[N], rate[N];
struct P{int i;double x, y, d;
	bool operator<(const P& b)const {return d > b.d;}
	inline void init() {
		x = f[i]/(b[i] + rate[i]*a[i]);
		y = f[i]*rate[i]/(b[i] + rate[i]*a[i]);
	}
}p[N], q[N];
double slope(int i, int j) {
	if (fabs(p[i].x - p[j].x) < EPS) return 1e20;
	return (p[i].y - p[j].y)/(p[i].x - p[j].x);
}
void solve(int l, int r) {
	if (l == r) {
		f[l] = max(f[l], f[l - 1]);
		p[l].init();
		return;
	}
	int mid = (l + r) >> 1;
	for (int k = l, i = 0, j = mid - l + 1; k <= r; k++) q[(p[k].i <= mid ? i : j)++] = p[k];
	memcpy(p + l, q, (r - l + 1)*sizeof(P));
	solve(l, mid);
	int top = 0;
	for (int i = l; i <= mid; i++) {
		while (top > 1 && slope(sk[top], sk[top - 1]) < slope(sk[top], i)) top--; 
		sk[++top] = i;
	}
	for (int x = 1, y = mid + 1; y <= r; y++) {
		while (x < top && slope(sk[x], sk[x + 1]) + EPS > p[y].d) x++;
		int i = p[y].i, j = sk[x];
		f[i] = max(f[i], p[j].x*b[i] + p[j].y*a[i]);
	}
	solve(mid + 1, r);
	int tot = 0;
	for (int i = l, j = mid + 1; i <= mid || j <= r; tot++) {
		if (i > mid || (j <= r && p[j].x < p[i].x)) q[tot] = p[j++];
		else q[tot] = p[i++];
	}
	memcpy(p + l, q, tot*sizeof(P));
}
int main() {
	freopen("cash.in", "r", stdin);
	freopen("cash.out", "w", stdout);
	scanf("%d%lf", &n, f);
	for (int i = 1; i <= n; i++) scanf("%lf%lf%lf", a + i, b + i, rate + i), p[i].d = -b[i]/a[i], p[i].i = i;
	std::sort(p + 1, p + 1 + n);
	solve(1, n);
	printf("%.3lf\n", f[n]);
}
