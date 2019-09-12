#include <cstdio>
#define file(x) "storage." #x
typedef long long ll;
const int N = 1000010;
int n, q[N], sz, tail, head;
ll p[N], g[N], c[N], d[N], f[N];
inline double x(int i) {return p[i];}
inline double y(int i) {return f[i] + g[i];}
inline double slope(int i, int j) {return (y(i) - y(j))/(x(i) - x(j));}
int main() {
//	freopen("input", "r", stdin);
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", d + i, p + i, c + i);
		g[i] = g[i - 1] + p[i]*d[i];
		p[i] += p[i - 1];
		while (head + 1 != tail && slope(q[tail - 1], q[tail - 2]) >slope(q[tail - 1], i - 1)) tail--;
		q[tail++] = i - 1;
		while (head + 1 != tail && slope(q[head], q[head + 1]) < d[i]) head++;
		int j = q[head];
		f[i] = f[j] + d[i]*(p[i] - p[j]) - (g[i] - g[j]) + c[i];
	}
	printf("%lld\n", f[n]);
}
