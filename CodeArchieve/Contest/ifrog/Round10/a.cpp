#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
using std::max;
typedef long long ll;
const int M = 1e9 + 7, N = 1e6 + 10;
ll f[N][2];
inline ll sum(int i, int j, int t) {return i >= j ? (f[i][t] - f[j - 1][t] + M)%M: 0;}
int solve(int n, int a, int b) {
	memset(f, 0, sizeof(f));
	f[0][1] = 1;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < a; j++) if (i - j >= 0) f[i][1] = (f[i][1] + f[i - j][0])%M;
//		for (int j = 1; j < b; j++) if (i - j >= 0) f[i][0] = (f[i][0] + f[i - j][1])%M;
		f[i][0] = sum(i - 1, max(i - b + 1, 0), 1);
		f[i][1] = sum(i - 1, max(i - a + 1, 0), 0);
		f[i][0] = (f[i - 1][0] + f[i][0])%M;
		f[i][1] = (f[i - 1][1] + f[i][1])%M;
	}
	return (sum(n, n, 0) + sum(n, n, 1))%M;
}
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		printf("%d\n", solve(n, a, b));
	}
}
