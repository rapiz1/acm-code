#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
int n;
bool vis[N];
vector<int> pri;
int main() {
	cin >> n;
	pri.push_back(1);
	for (int i = 2; i < N; i++) {
		if (!vis[i]) pri.push_back(i), vis[i] = 1;
		for (int j = 1; j < pri.size(); j++) {
			long long v = (long long)i*pri[j];
			if (v >= N) break;
			vis[v] = 1;
			if (i%pri[j] == 0) break;
		}
	}
	for (int i = 0; i < pri.size(); i++) if (pri[pri[i]] >= n) {
		cout << pri[pri[i]];
		break;
	}
}
