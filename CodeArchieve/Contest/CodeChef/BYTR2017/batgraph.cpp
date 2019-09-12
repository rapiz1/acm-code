#include <cstdio>
#include <cstring>
#include <algorithm>
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (v != fa) 
using std::min;
const int N = 1e5 + 10;
int n, m, hed[N], nxt[N << 1], du[N], sz, clk, dfn[N], scid[N], scnt;
bool bri[N << 1];
struct EDGE{int u, v;}st[N << 1];
inline void _add(int u, int v) {
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v){
	_add(u, v), _add(v, u);
}
int tarjan(int u, int fa) {
	int lowu = dfn[u] = ++clk;;
	fore {
		if (dfn[v]) {
			lowu = min(lowu, dfn[v]);
		}
		else {
			int lowv = tarjan(v, u);
			lowu = min(lowu, lowv);
			if (lowv > dfn[u]) bri[e] = bri[e^1] = 1;
		}
	}
	return lowu;
}
void dfs(int u, int fa) {
	if (scid[u]) return;
	scid[u] = scnt;
	fore if (!bri[e]) {
		dfs(v, u);
	}
}
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		sz = 1;
		clk = 1;
		scnt = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(bri, 0, sizeof(bri));
		memset(hed, 0, sizeof(hed));
		memset(nxt, 0, sizeof(nxt));
		memset(du, 0, sizeof(du));
		memset(st, 0, sizeof(st));
		memset(scid, 0, sizeof(scid));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		tarjan(1, 0);
		for (int i = 1; i <= n; i++) ++scnt, dfs(i, 0);
		for (int i = 2; i <= sz; i += 2) if (scid[st[i].u] != scid[st[i].v]) du[st[i].u]++, du[st[i].v]++;
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += du[i] == 1;
		printf("%d\n", ans/2*1500);
	}
}
