#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define fore for(int i = 0; i < (int)to[u].size(); i++)
using namespace std;
typedef pair<long long ,long long> poi;
const int N = 35;
const poi dd[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
poi operator+(const poi& a, const poi& b) {return make_pair(a.first + b.first, a.second + b.second);}
poi operator*(const poi& a, long long b) {return make_pair(a.first*b, a.second*b);}
int n, son[N], du[N];
poi pos[N];
vector<int> to[N];
void dfs(int u, int fa, int fdi, long long dis) {
	int di = 0;
	fore {
		int v = to[u][i];
		if (v == fa) continue;
		if (fdi != -1 && di == (fdi + 2)%4) di++;
		pos[v] = dd[di]*dis + pos[u];
		dfs(v, u, di, dis >> 1);
        di++;
	}
}
int main() {
//	freopen("input", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
		du[u]++,du[v]++;
	}
	for (int i = 1; i <= n; i++) if (du[i] > 4) {
		puts("NO");
		return 0;
	}
	pos[1] = {1, 1};
	dfs(1, 0, -1, 1ll << 31);
	puts("YES");
	for (int i = 1; i <= n; i++) cout << pos[i].first << " " << pos[i].second << endl;
}
