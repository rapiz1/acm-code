#include <cstdio>
#include <algorithm>
#define file(x) "menci_journey." #x
using std::min;
const int N = 3010;
typedef long long ll;
int n, m, q[N], sz, head, tail;
ll f[N][N], a[N];
inline double x(int i) {return a[i];}
inline double y(int i, int d) {return f[d][i] + 1.0*a[i]*a[i];}
inline double slope(int i, int j, int d) {return (y(i, d) - y(j, d))/(x(i) - x(j));}
int main() {
//	freopen("input", "r", stdin);
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
	for (int i = 1; i <= n; i++) f[0][i] = 0x3f3f3f3f;
	f[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		head = tail = 0;
		for (int j = 1; j <= n; j++) {
			while (head + 1 != tail && slope(q[tail - 1], q[tail - 2], i - 1) > slope(q[tail - 1], j - 1, i - 1)) tail--;
			q[tail++] = j - 1;
			while (head + 1 != tail && slope(q[head], q[head + 1], i - 1) < 2*a[j]) head++;	
			int k = q[head];
			f[i][j] = f[i - 1][k] + (a[j] - a[k])*(a[j] - a[k]);
		}
	}
	ll s = f[m][n];
	printf("%lld", m*s-a[n]*a[n]);
}
