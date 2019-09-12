#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll n, s, t, a[N], c, inq ,ans = 1e15, ti;
inline void upd(ll ti, ll ans) {
	if (::ans > ans) ::ans = ans, ::ti = ti;
}
int main() {
//	freopen("input", "r", stdin);
	cin >> s >> t >> c >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (n && a[n] > t) n--;
	ll nt = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j + 1 <= n && a[j + 1] == a[i]) j++;
		int cnt = j - i + 1;
		if (a[i] - 1 >= 0) if (max(max(a[i] - 1, nt), s) + c <= t) upd(a[i] - 1, max(max(nt, s) - (a[i] - 1), 0ll));
		if (max(max(a[i], nt), s) + cnt*c <= t) upd(a[i], max(max(nt, s) - a[i], 0ll) + cnt*c);
		nt = max(max(a[i], nt), s) + cnt*c;
		if (nt >= t) break;
		i = j;
	}
	if (max(nt, s) + c <= t) upd(max(nt, s), 0);
	cout << ti;
}
