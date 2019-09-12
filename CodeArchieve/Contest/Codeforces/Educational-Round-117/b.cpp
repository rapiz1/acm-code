#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;
vector<int> mo[2];
int a, b, c, m, n;
ll ans;
int main() {
//	freopen("input", "r", stdin);
	cin >> a >> b >> c >> m;
	for (int i = 1; i <= m; i++) {
		int v;
		string t;
		cin >> v >> t;
		int x = t == "USB" ? 0 : 1;
		mo[x].push_back(v);
	}
	sort(mo[0].begin(), mo[0].end());
	sort(mo[1].begin(), mo[1].end());
	int i, j;
	for (i = 0; i < a && i < mo[0].size(); i++) ans += mo[0][i],++n;
	for (j = 0; j < b && j < mo[1].size(); j++) ans += mo[1][j],++n;
	int x = 0;
	while (x != c && (i < mo[0].size() || j < mo[1].size())) {
		if (i == mo[0].size() || (j < mo[1].size() && mo[1][j] <= mo[0][i])) ans += mo[1][j++];
		else ans += mo[0][i++];
		++x;
	}
	cout << n + x << " " << ans;
}
