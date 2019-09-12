#include <cstdio>
#define file(x) "special." #x
const int N = 1e6 + 10;
typedef long long ll;
int n, tail, head, q[N], sz;
ll a, b, c, f[N], s[N];
inline double x(int i) {return s[i];}
inline double y(int i) {return f[i] + 1.0*a*s[i]*s[i] - 1.0*b*s[i];}
inline double slope(int i, int j) {return (y(i) - y(j))/(x(i) - x(j));}
inline ll sq(ll x) {return x*x;}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%lld%lld%lld", &n, &a, &b, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
		s[i] += s[i - 1];
		while (head + 1 != tail && slope(q[tail - 2], q[tail - 1]) < slope(q[tail - 1], i - 1)) tail--;
		q[tail++] = i - 1;
		while (head + 1 != tail && slope(q[head], q[head + 1]) > 2*a*s[i]) head++;
		int j = q[head];
		f[i] = f[j] + a*sq(s[i] - s[j]) + b*(s[i] - s[j]) + c;
	}
	printf("%lld\n", f[n]);
}
