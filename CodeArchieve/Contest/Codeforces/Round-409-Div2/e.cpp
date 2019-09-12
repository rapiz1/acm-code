#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int n, m, f[N];
bool ban[N], vis[N];
vector<int> to[N], ret;
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
void exgcd(int a, int b, int& d, int& x, int& y) {
	if (!b) x = 1, y = 0, d = a;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
int dfs(int u) {
	if (vis[u]) return f[u];
	vis[u] = 1;
	f[u] = u < m;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		f[u] = max(f[u], dfs(v) + (u < m));
	}
	return f[u];
}
void go(int u) {
	if (u < m) ret.push_back(u);
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (!ban[v] && f[v] == f[u] + (u < m)) {
			go(v);
			break;
		}
	}
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), ban[x] = 1;
	for (int i = 0; i < m; i++) if (!ban[i]) {
		int d = gcd(i, m);
		to[i].push_back(m + d);
	}
	for (int i = 1; i < m; i++) for (int x = i; x < m; x += i) if (!ban[x]) to[m + i].push_back(x);
	int mx = 0;
	for (int i = 0; i < m; i++) if (!ban[i]) mx = max(mx, dfs(i));
	for (int i = 0; i < m; i++) if (mx == f[i]) {
		go(i);
		for (int j = 0; j < (int)ret.size(); j++) printf("%d ", ret[j]);
		return 0;
	}
}
