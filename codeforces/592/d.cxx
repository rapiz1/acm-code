/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 15 Oct 2019 22:37:39 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int,int> poi;
const int N = 1e5 + 10;
int n, rt, co[N];
ll c[N][3], f[N][3][3], ans;
poi rec[N][3][3];
vector<int> to[N], seq;
void dfs(int u, int prev) {
	seq.push_back(u);
	for (auto v : to[u]) if (v != prev) {
		dfs(v, u);
	}
}
int main() {
	cin >> n;
	for (int k = 0; k < 3; k++)
		for (int i = 1; i <= n; i++) 
			cin >> c[i][k];
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for (int i= 1; i <= n; i++) {
		if (to[i].size() > 2) {
			cout << -1;
			return 0;
		}
	}
	memset(f, 0x3f, sizeof f);
	ans = f[0][0][0];
	for (int i = 1; i <= n; i++) {
		if (to[i].size() == 1) {
			dfs(i, 0);
			break;
		}
	}
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			if (i != j)
				f[seq[1]][i][j] = c[seq[1]][i] + c[seq[0]][j], rec[seq[1]][i][j] = poi(j, 0);
	for (int i = 2; i < (int)seq.size(); i++) {
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 3; p++) if (p != j)
				for (int q = 0; q < 3; q++) if (p != q && j != q) {
					if (f[seq[i]][j][p] > c[seq[i]][j] + f[seq[i-1]][p][q]) {
						f[seq[i]][j][p] = c[seq[i]][j] + f[seq[i-1]][p][q];
						rec[seq[i]][j][p] = poi(p, q);
					}
				}
		}
	}
	poi now;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		if (ans > f[seq[seq.size() - 1]][i][j]) {
			ans = f[seq[seq.size() - 1]][i][j];
			now = poi(i, j);
			//xxx(i);xxx(j);
		}
	}
	cout << ans << endl;
	for (int i = seq.size() - 1; i >= 0; i--) {
		//xxx(now.first);
		//xxx(now.second);
		co[seq[i]] = now.first;
		now = rec[seq[i]][now.first][now.second];
	}
	for (int i = 1; i <= n; i++) cout << co[i]+1 << " ";
}

