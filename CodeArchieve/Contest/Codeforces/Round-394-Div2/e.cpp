#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#define fore for(int i = 0; i < (int)to[u].size(); i++)
using namespace std;
typedef pair<int, int> poi;
const int N = 35;
const poi dd[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
set<poi> mp;
poi operator+(const poi& a, const poi& b) {return make_pair(a.first + b.first, a.second + b.second);}
poi operator*(const poi& a, int b) {return make_pair(a.first*b, a.second*b);}
int n, m, fa[N], dep[N], fw[N], di[N], lca[N][N], son[N];
poi pos[N];
vector<int> to[N];
void mkrt(int u) {
	fore {
		fa[to[u][i]] = u;
		son[u]++;
		mkrt(to[u][i]);
	}
}
void dfs(int u) {
	fore {
		int v = to[u][i];
		fw[v] = 1;
		bool fd = 0;
		for (int j = 0; j < 4; j++) {
			poi c = dd[j]*fw[v] + pos[u];
			bool f = 1;
			for (int i = 1; i <= n; i++) if (pos[i] == c) {
				f = 0;
				break;
			}
			if (f) {
				fd = 1;
				di[v] = j;
				pos[v] = c;
				break;
			}
		}
		if (!fd) {
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
		pos[i] = {1e9, 1e9};
	}
	mkrt(1);
	for (int i = 1; i <= n; i++) if (son[i] > 4) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		int x = i, y = j;
		while (x != y) {
			if (dep[x] < dep[y]) swap(x, y);
			x = fa[x];
		}
		lca[i][j] = x;
	}
	dfs(1);
}
