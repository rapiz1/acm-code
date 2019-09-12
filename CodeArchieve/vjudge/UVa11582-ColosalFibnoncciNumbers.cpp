#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
const int N = 1010*1010;
typedef unsigned long long ull;
using namespace std;
int per[1010];
std::vector<int> f[1010];
int qpow(ull x, ull r, int per) {
	if (!x) return 0;
	int ret = 1;
	x %= per;
	while (r) {
		if (r&1) ret = ret*x%per;
		x = x*x%per, r>>=1;
	}
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	int T, n;
	ull	a, b;scanf("%d", &T);
	for (int k = 2; k <= 1000; k++) {
		f[k].push_back(0), f[k].push_back(1);
		for (int i = 2; i <= k*k; i++) {
			f[k].push_back((f[k][i - 1] + f[k][i - 2])%k);
			if (f[k][i] == 1 && f[k][i - 1] == 0) {
				per[k] = i - 1;
				break;
			}
		}
	}
	while (T--) {
		cin >> a >> b >> n;
		if (n == 1) puts("0");
		else printf("%d\n", f[n][qpow(a, b, per[n])]);
	}
}
