#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> data;
const int MOD = 1e9 + 9, S = 1e5 + 10, D = 110;
int d, m, f[S][D];
ll s;
struct Mat {
	int n, m, a[D][D];
	void init(int x, int y) {n = x, m = y;memset(a, 0, sizeof a);}
}ans, trans;
int zip(int i, int j) {return (i - 1)*m + j;}
void mul(Mat& a, Mat& b) {
	Mat c;
	c.init(a.n, b.m);
	for (int i = 1; i <= c.n; i++) for (int j = 1; j <= c.m; j++)
		for (int k = 1; k <= a. m; k++) c.a[i][j] = (c.a[i][j] + (ll)a.a[i][k]*b.a[k][j])%MOD;
	a = c;
}
int main() {
//	freopen("input", "r", stdin);
	cin >> s >> m >> d;
	trans.init(zip(m, m), zip(m, m));
	ans.n = 1, ans.m = zip(m, m);
	if (m > s) m = s;
	for (int i = 1; i <= m; i++) {
		ans.a[1][zip(i, i)] = 1;
		for (int j = 1; j <= i; j++) {
			for (int k = max(j - d, 1); k <= min(j + d, m); k++) {
				ans.a[1][zip(i, j)] += ans.a[1][zip(i - j, k)];
			}
		}
	}
	s -= m;
	for (int i = 1; i < m; i++) for (int j = 1; j <= m; j++) {
		trans.a[zip(i + 1, j)][zip(i, j)] = 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = max(i - d, 1); j <= min(i + d, m); j++) {
			trans.a[zip(m - i + 1, j)][zip(m, i)] = 1;
		}
	}
	while (s) {
		if (s&1) mul(ans, trans);
		mul(trans, trans), s>>=1;
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) sum = (sum + ans.a[1][zip(m, i)])%MOD;
	printf("%d\n", sum);
}
