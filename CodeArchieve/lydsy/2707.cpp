#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
namespace I {
	const int L =  1 << 15 | 1;
	char *s, *t, buf[L];
	inline char gc() {
		return s == t ? t=(s=buf)+fread(buf, 1, L, stdin), *s++ : *s++;
	}
	inline int gi() {
		int x = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x=x*10+ch-'0', ch = gc();
		return x;
	}
}using I::gi;
const int N = 300, V = 1e4 + 10;
std::vector<int>to[V], sc[V], nt[V];
int n, m, s, t, clk, dfn[V], id[V], scc, sk[V], top, th[V], vaild[V];
double x[N][N], f[V];
int dfs(int u) {
	sk[++top] = u;
	int lowu = dfn[u] = ++clk;
	for (int i = 0 ;i  <(int)to[u].size(); i++) {
		int v =  to[u][i];
		if (!dfn[v]) lowu = std::min(lowu, dfs(v));
		else if (!id[v]) lowu = std::min(lowu, dfn[v]);
	}
	if (lowu == dfn[u]) {
		int x;
		++scc;
		do {
			x = sk[top--];
			sc[id[x] = scc].push_back(x);
		}while (x != u);
	}
	return lowu;
}
void gaess(int n) {
	for (int i = 1; i <= n; i++) {
		double tmp = x[i][i];
		for (int j = 1; j <= n + 1; j++) x[i][j] /= tmp;
		for (int j = 1; j  <= n; j++) if (i != j) {
			for (int k = n + 1; k >= i; k--) x[j][k] -= x[i][k]*x[j][i];
		}
	}
}
bool solve(int u) {
	if (vaild[u] != -1) return vaild[u];
	if (u != id[t])  {
		std::vector<int>& ut=nt[u];
		for (int i = 0; i < (int)sc[u].size(); i++) {
			int x = sc[u][i];
			for (int j = 0; j < (int)to[x].size(); j++) ut.push_back(id[to[x][j]]);
		}
		std::sort(ut.begin(), ut.end());
		ut.resize(std::unique(ut.begin(), ut.end()) - ut.begin());
		for (int i = 0; i < (int)ut.size(); i++) if (ut[i] != u) {
			if (solve(ut[i])) vaild[u]=1;
			else return (vaild[u]=0);
		}
		if (vaild[u] == -1) return (vaild[u] = 0);
		int n = sc[u].size();
		for (int i = 0; i < (int)sc[u].size(); i++) {
			int x = sc[u][i];
			::x[i+1][i+1]=to[x].size();
			if (x != t) for (int j = 0; j < (int)to[x].size(); j++) {
				int y = to[x][j];
				if (id[x] == id[y]) ::x[i + 1][th[y]] = -1;
				else ::x[i+1][n + 1] += f[y];
			}
			::x[i+1][n+1]+=to[x].size();
		}
		gaess(n);
		for(int i = 0; i < (int)sc[u].size(); i++) f[sc[u][i]] = x[i + 1][n + 1];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n+1; j++) x[i][j]=0;
	}
	else vaild[u]=1;
	return vaild[u];
}
void brute() {
	for (int i = 1; i <= n; i++){
		if (i != t) {
			for (int j = 0; j < (int)to[i].size(); j++) {
				int k = to[i][j];
				x[i][k] = -1.0/to[i].size();
			}
			x[i][n+1]=1;
		}
		x[i][i]=1;
	}
	gaess(n);
	printf("%.3lf\n", x[s][n+1]);
}
int main() {
//	freopen("input", "r", stdin);
//	n=gi(),m=gi(),s=gi(),t=gi();
	scanf("%d%d%d%d", &n, &m, &s, &t);
	memset(vaild, -1, sizeof vaild);
	for (int i = 1, u, v; i <= m; i++) /*u=gi(),v=gi(),*/scanf("%d%d", &u, &v), to[u].push_back(v);
	to[t].resize(0);
	dfs(s);
	for (int i = 1; i <= n; i++) if (i != t && dfn[i] && to[i].size() == 0) {
		puts("INF");
		return 0;
	}
	if (!dfn[t]) {
		puts("INF");
		return 0;
	}
	for (int i = 1; i<= scc; i++) for (int j = 0 ;j < (int)sc[i].size(); j++) th[sc[i][j]] = j + 1;
	/*
	if (solve(id[s])) printf("%.3lf\n", f[s]);
	else puts("INF");
	*/
	solve(id[s]);
	printf("%.3lf\n", f[s]);
}
