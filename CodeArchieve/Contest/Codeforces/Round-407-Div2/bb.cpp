#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
typedef map<ll, int>::iterator IT;
ll b1, q, l, n;
set<int> st;
map<ll, int> show;
int main() {
	cin >> b1 >> q >> l >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;st.insert(x);
	}
	int ans = 0;
	for (ll x = b1, i = 1; i <= 60 && abs(x) <= l; x*=q, i++) {
		ans += !st.count(x);
		show[x]++;
	}
	for (IT it = show.begin(); it != show.end(); it++) {
		if (it->second > 1 && !st.count(it->first)) {
			puts("inf");
			return 0;
		}
	}
	cout << ans;
}
