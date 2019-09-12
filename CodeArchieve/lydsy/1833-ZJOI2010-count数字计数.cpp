#include <cstdio>
const int N = 20;
typedef long long ll;
ll f[N], ten[N], ans[N];
int a[N], sz;
void calc(ll x, int y) {
	if (x < 0) return;
	if (!x) return;
	sz = 0;
	for (ll i = x; i; i/=10) a[++sz] = i%10;
	for (int i = 1; i < sz; i++) {
		for (int j = 0; j < 10; j++)
			for (int k = 1; k < 10; k++)
				ans[j] += y*(f[i - 1] + (k == j)*ten[i - 1]);
	}
	for (int i = 1; i < a[sz]; i++) for (int j = 0; j < 10; j++) ans[j] += y*f[sz - 1] + y*(i == j)*ten[sz - 1];
	ans[a[sz]] += x%ten[sz - 1]*y;
	for (int i = sz - 1; i; i--) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < a[i]; k++) ans[j] += y*f[i - 1] + y*(j == k)*ten[i - 1];
		}
		ans[a[i]] += x%ten[i - 1]*y;
	}
	for (int i = 1; i <= sz; i++) ans[a[i]] += y;
}
int main() {
//	freopen("input", "r", stdin);
	ll a, b; scanf("%lld%lld", &a, &b);
	ten[0] = 1;
	for (int i = 1; i < N; i++) ten[i] = ten[i - 1]*10;
	for (int i = 1; i < N; i++) f[i] = f[i - 1]*10 + ten[i - 1];
	calc(a - 1, - 1), calc(b, 1);
	if (!a) ans[0]++;
	for (int i = 0; i < 9; i++) printf("%lld ", ans[i]);
	printf("%lld\n", ans[9]);
}
