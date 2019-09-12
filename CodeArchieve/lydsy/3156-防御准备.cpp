#include <cstdio>
const int N = 1e6 + 10;
typedef long long ll;
int n, h, t, q[N];
ll f[N], a[N];
inline double y(ll i) {return f[i] + (i*i + i)/2.0;}
inline double slope(int i, int j) {return (y(i) - y(j))/(i - j);}
inline ll cost(ll i) {return i*(i - 1)/2;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		while (h + 1 != t && slope(q[t - 2], q[t - 1]) > slope(q[t - 1], i - 1)) t--;
		q[t++] = i - 1;
		while (h + 1 != t && slope(q[h], q[h + 1]) < i) h++;
		int j = q[h];
		f[i] = f[j] + cost(i - j) + a[i];
	}
	printf("%lld\n", f[n]);
}
