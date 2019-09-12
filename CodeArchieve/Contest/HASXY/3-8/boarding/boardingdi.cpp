#include <cstdio>
#include <cstring>
#include <algorithm>
#define file(x) "boarding." #x
typedef long long ll;
const int N = 2e5 + 10;
int n, s[N];
ll f[N], t[N], nt[N];
int main() {
	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = n; i >=1; i--) scanf("%d%lld", &s[i], &t[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < s[i]; j++) f[i] = std::max(f[i], nt[j]);
		f[i] += t[i];
		f[i] = std::max(f[i], i - 1ll + s[i]);
		nt[s[i]] = f[i];
	}
	printf("%lld\n", f[n]);
}
