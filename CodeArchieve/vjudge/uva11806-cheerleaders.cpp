#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int C = 500;
const ll M = 1000007;
int n, m, k;
long long c[C][C];
long long solve() {
	ll ret = 0;
	for (int s = 1; s < 1 << 4; s++) {
		int row = n, col = m, d = 0;
		for (int j = 0; j < 4; j++) if (s>>j&1) {
			d++;
			if (j == 0 || j == 1) row--;
			else col--;
		}
		d = d%2 ? 1: -1;
		ret = (ret + d*c[row*col][k] + M)%M;
	}
	return (c[n*m][k] - ret + M)%M;
}
int main() {
//	freopen("input", "r", stdin);
	int ks; cin >> ks;
	c[0][0] = 1;
	for (int i = 1; i < C; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%M;
	}
	for (int i = 1; i <= ks; i++) {
		cin >> n >> m >> k;
		printf("Case %d: %lld\n", i, solve());
	}
}
