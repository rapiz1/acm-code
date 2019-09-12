#include <cstdio>
#include <cstring>
#include <vector>
#define file(x) "zjoi15_substring." #x
const int N = 21*2e5 + 10, C = 10;
int n, c, co[N], du[N];
std::vector<int> to[N];
long long ans;
int sz = 1, nxt[N][C], pre[N], val[N];
int extend(int c, int p) {
//	if (nxt[p][c] && val[nxt[p][c]] == val[p] + 1) return nxt[p][c];
	int np = ++sz;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	ans += val[np] - val[pre[np]];
	return np;
}
void dfs(int u, int p, int fa) {
	p = extend(co[u], p);
	for (int i = 0; i < to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa) continue;
		dfs(v, p, u);
	}
}
int main() {
//	freopen("input", "r", stdin);
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d", co + i);
	for (int i = 1; i < n; i++) {
		int u, v;scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
		du[u]++, du[v]++;
	}
	for (int i = 1; i <= n; i++) if (du[i] == 1) dfs(i, 1, -1);
	printf("%lld\n", ans);
}
