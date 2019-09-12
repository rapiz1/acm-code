#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 1010;
int n, as;
int x[N], v[N], ans = 1e9, tar;
int main() {
	cin >> n >> tar;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		int xx = abs(x[i] - tar)/v[i];
		if (xx < ans) ans = xx, as = i;
	}
	int cc = 0;
	for (int i = 1; i <= n; i++) {
		int xx = abs(x[i] - tar)/v[i];
		if (xx == ans) cc++;
	}
	if (cc == 1) cout << as - 1;
	else cout << -1;
}
