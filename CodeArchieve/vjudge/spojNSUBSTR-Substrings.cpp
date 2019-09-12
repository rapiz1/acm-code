#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
const int N = 6e5;
int n, sz = 1, par[N], nxt[N][26], step[N], last = 1, f[N], right[N];
bool vis[N];
std::vector<int> to[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	step[np] = step[last] + 1;
	right[np] = 1;
	for (; p && !nxt[p][c]; p = par[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (step[q] == step[p] + 1)  par[np] = q;
		else {
			int nq = ++sz;
			step[nq] = step[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof(nxt[0]));
			par[nq] = par[q], par[q] = nq, par[np] = nq;
			for (;p && nxt[p][c] == q; p = par[p]) nxt[p][c] = nq;
		}
	}else par[np] = 1;
	last = np;
}
int dfs(int u) {
	for (int i = 0; i < to[u].size(); i++) right[u] += dfs(to[u][i]);
	f[step[u]] = std::max(f[step[u]], right[u]);
	return right[u];
}
int main() {
	freopen("input", "r", stdin);
	char ch;
	while (isalpha(ch = getchar())) n++, extend(ch - 'a');
	for (int i = 1; i <= sz; i++) to[par[i]].push_back(i);
	dfs(1);
	for (int i = n - 1; i; i--) f[i] = std::max(f[i], f[i + 1]);
	for (int i = 1; i <= n; i++) printf("%d\n", f[i]);
}
