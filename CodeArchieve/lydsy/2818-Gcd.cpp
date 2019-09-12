#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
typedef long long ll;
int n;
ll phi[N], ans;
vector<int> pri;
int main() {
//	freopen("input", "r", stdin);
	cin >> n;
	phi[1] = 1;
	for (int i = 2; i <= n; i++) if (!phi[i]) {
		pri.push_back(i);
		phi[i] = i;
		for (int j = i; j <= n; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i - 1);
		}
	}
	for (int i = 2; i <= n; i++) phi[i] += phi[i - 1];
	for (int i = 0; i < (int)pri.size(); i++) {
		int p = pri[i];
		ans += phi[n/p]*2;
	}
	cout << ans - pri.size();
}
