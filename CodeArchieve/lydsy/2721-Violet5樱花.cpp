#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7, N = 1e7 + 10;
int n, ans = 1;
bool vis[N];
vector<int> pri;
int main() {
	cin >> n;
	for (int i = 2; i < N; i++) {
		if (!vis[i]) vis[i] = 1, pri.push_back(i);
		for (int j = 0; j < (int)pri.size(); j++) {
			ll k = i*pri[j];
			if (k>N) break;
			vis[k] = 1;
			if (i%pri[j] == 0) break;
		}
	}
	for (int i = 0; i < (int)pri.size() && pri[i] <= n; i++) {
		int cc = 0, k = pri[i];
		for (int x = n; x; x/=k) cc += x/k;
		cc=cc<<1|1;
		ans = (ll)ans*cc%M;
	}
	cout << ans;
}
