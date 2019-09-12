#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, x[N], y[N], cs, cr, ans;
inline double sq(double x) {return x*x;}
double dis(int i, int j) {return sq(x[i] - x[j]) + sq(y[i] - y[j]);}
void solve() {
	cin >> n >> cs >> cr;
	ans = n*cs;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < 1 << n; i++) {
		int nc = 0;
		for (int j = 0; j < n; j++) if (i>>j&1) nc += c;
	}
}
int main() {
	int T;cin >> T;
	while (T--) solve();
}
