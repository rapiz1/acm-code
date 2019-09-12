#include <cstdio>
#include <algorithm>
#include <cstdlib>
const int N = 18;
typedef long long ll;
ll f[N][10];
int a[N], sz;
ll count(ll n) {
	if (!n) return 0;
	 sz = 0;
	 for (;n;n/=10) a[++sz] = n%10;
	 n = sz;
	 ll ret = 0;
	 for (int i = 1; i < a[n]; i++) ret += f[n][i];
	 for (int i = 1; i < sz; i++) for (int j = 1; j <= 9; j++) ret += f[i][j];
	 int flag = 1;
	 for (int i = n - 1; i; i--) {
		 for (int j = 0; j < a[i]; j++) if (abs(a[i + 1] - j) >= 2) ret += f[i][j];
		 if (abs(a[i + 1] - a[i]) < 2) {
			 flag = 0;
			 break;
		 }
	 }
	 return ret + flag;
}
int main() {
//	freopen("input", "r", stdin);
	for (int i = 0; i <= 9; i++) f[1][i] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++) if (abs(j - k) >= 2) f[i][j] += f[i - 1][k];
	ll a, b;scanf("%lld%lld", &a, &b);
	printf("%lld", count(b) - count(a - 1));
}
