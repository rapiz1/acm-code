#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
int main() {
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		if (n > m) swap(n, m);
		ans = m*n*(n - 1) + n*m*(m - 1) + 2*((m - n + 1)*n*(n - 1) + (n*(n-1)*(2*n-1)/6 - n*(n-1)/2)*2);
		cout << ans << endl;
	}
}
