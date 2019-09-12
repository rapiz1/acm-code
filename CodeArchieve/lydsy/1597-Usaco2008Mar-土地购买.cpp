#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 5e4 + 10;
struct S{ll x, y;
	void rd(){scanf("%lld%lld",&x,&y);}
}st[N];
bool cmp(const S& a, const S& b) {return a.x < b.x || (a.x == b.x && a.y > b.y);}
int n, q[N], h, t, tot;
ll f[N], x[N], y[N];
inline double slope(int i, int j) {return (double(f[i]) - f[j])/(double(y[i + 1]) - y[j + 1]);}
int main() {
//	freopen("input", "r", stdin);
//  freopen("acquire.in", "r", stdin);
//  freopen("acquire.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) st[i].rd();
	std::sort(st + 1 , st + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		while (tot && y[tot] <= st[i].y) tot--;
		y[++tot] = st[i].y, x[tot] = st[i].x;
	}
	for (int i = 1; i <= tot; i++) {
		while (h + 1 != t && slope(q[t - 1], q[t - 2]) < slope(q[t - 1], i - 1)) t--; 
		q[t++] = i - 1;
		while (h + 1 != t && slope(q[h], q[h + 1]) > -x[i]) h++;
		int j = q[h];
		f[i] = f[j] + y[j + 1]*x[i];
	}
	printf("%lld\n", f[tot]);
}
