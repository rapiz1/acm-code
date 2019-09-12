#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n;
ll a[N], ans = -2e14;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		a[i] = abs(a[i] - a[i + 1]);
		if (i%2) a[i]*=-1;
	}
	n--;
	ll now = 0;
	for (int i = 1; i <= n; i++) {
		now += a[i];
		ans = max(ans, now);
		if (now < 0) now = 0;
	}
	for (int i = 1; i <= n; i++) a[i]*=-1;
	now = 0;
	for (int i = 1; i <= n; i++) {
		now += a[i];
		ans = max(ans, now);
		if (now < 0) now = 0;
	}
	cout << ans;
}
