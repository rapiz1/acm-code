#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
vector<ll> st;
int main() {
	cin >> n >> k;
	for (ll j = 1; j <= n/j; j++) if (n%j == 0) {
		st.push_back(j);
		if (j != n/j) st.push_back(n/j);
	}
	sort(st.begin(), st.end());
	if (k <= st.size()) cout << st[k - 1];
	else cout << -1;
}
