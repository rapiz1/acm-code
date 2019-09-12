#include <bits/stdc++.h>
using namespace std;
int n, m;
double ans;
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		ans += (pow(i/double(m), n) - pow((i - 1.0)/m, n))*i;
	}
	cout.setf(ios::fixed);
	cout << setprecision(9) << ans;
}
