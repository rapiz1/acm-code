#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll b1, q, l, n;
set<int> st;
int main() {
	cin >> b1 >> q >> l >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;st.insert(x);
	}
	if (b1 == 0) {
		if (st.count(0)) puts("0");
		else puts("inf");
	}
	else {
		if (q == 0) {
			if (!st.count(0)) puts("inf");
			else if (abs(b1) <= l && !st.count(b1)) puts("1");
			else puts("0");
		}
		else if (q == 1) {
			if (st.count(b1) || abs(b1) > l) puts("0");
			else puts("inf");
		}
		else if (q == -1) {
			if (abs(b1) > l) puts("0");
			else if (!st.count(b1) || !st.count(-b1)) puts("inf");
			else puts("0");
		}
		else {
			int ans = 0;
			for (;abs(b1)<=l; b1*=q) ans += !st.count(b1);
			cout << ans;
		}
	}
}
