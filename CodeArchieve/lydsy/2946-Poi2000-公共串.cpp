#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int N = 4010*6;
int n, sz = 1, pre[N], nxt[N][26], val[N], mat[N][6], last = 1, ans, T;
std::vector<int> to[N];
char s[int(4e3)];
inline void extend(int c) {
	int np = ++sz, p = last;
	val[np] = val[p] + 1;
	mat[np][T] = 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			pre[nq] = pre[q], val[nq] = val[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
void dfs(int u) {
	for (int  i = 0; i < to[u].size(); i++) {
		int v = to[u][i];
		dfs(v);
		for (int j = 1; j <= n; j++) mat[u][j] = mat[u][j] || mat[v][j];
	}
	int cc = 0;
	for (int i = 1; i <= n; i++) cc += mat[u][i];
	if (cc == n) ans = std::max(ans, val[u]);
}
int main(){ 
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		last = 1;
		T = i;
		for (int j = 0; s[j]; j++) extend(s[j] -'a');
	}
	for (int i = 1; i <= sz; i++) to[pre[i]].push_back(i);
	dfs(1);
	printf("%d\n", ans);
}
