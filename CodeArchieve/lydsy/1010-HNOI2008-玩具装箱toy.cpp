#include <cstdio>
typedef long long ll;
const int N = 5e4 + 10;
int n, q[N], sz, head, tail;
ll f[N], c[N], l;
inline double y(ll i) {return f[i] + (i + c[i])*1.0*(i + c[i]);}
inline double x(ll i) {return i + c[i];}
inline double slope(int j, int k) {//j < k
	return (y(j) - y(k))/(x(j) - x(k));
}
inline ll sq(ll x) {return x*x;}
int main() {
	freopen("bzoj_1010.in", "r", stdin);
    freopen("bzoj_1010.out", "w", stdout);
	scanf("%d%lld", &n, &l);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", c + i), c[i] += c[i - 1];
		while (head + 1 != tail && slope(q[tail - 2], q[tail - 1]) > slope(q[tail - 1], i - 1)) tail--;
		q[tail++] = i - 1;
		while (head + 1 != tail && slope(q[head], q[head + 1]) < 2*(i + c[i] - l)) head++;
		int j = q[head];
		f[i] = f[j] + sq(i - j - 1 + c[i] - c[j] - l);
	}
	printf("%lld", f[n]);
}
