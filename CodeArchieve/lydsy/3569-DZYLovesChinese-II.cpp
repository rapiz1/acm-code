#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
const int N = 1e5 + 10, E = 1e6, K = 64;
struct Edge{int u, v, i;}st[E];
typedef unsigned long long ull;
int n, m, q, hed[N], nxt[E], sz, ans;
ull hs[int(5e5 + 10)], ta[N], u[K];
void _add(int u, int v, int i) {
	st[++sz] = {u, v, i};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int i) {
	_add(u, v, i), _add(v, u, i);
}
bool ins[N];
void dfs(int u, int fa) {
	ins[u] = 1;
	for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) {
		if (ins[v]) ta[u]^=hs[st[e].i];
		else hs[st[e].i] = 0, dfs(v, u);
	}
}
void dfs2(int u, int fa) {
	ins[u] = 1;
	for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
		if (!ins[v]) dfs2(v, u), ta[u] ^= ta[v], hs[st[e].i] ^= ta[v];
}
int main(){
	srand(1133123);
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) 
		scanf("%d%d", &u, &v), add(u, v, i), hs[i] = (ull)rand()*rand();
	dfs(1, 0);
	memset(ins, 0, sizeof ins);
	dfs2(1, 0);
	scanf("%d", &q);
	while (q--) {
		int k; scanf("%d", &k);
		memset(u, 0, sizeof u);
		bool f = 1;
		for (int i = 1; i <= k; i++) {
			int t;
			scanf("%d", &t);
			ull c = hs[t^ans];
			for (int i = K - 1; ~i; i--) if (c>>i&1) {
				if (u[i]) c ^= u[i];
				else {
					u[i] = c;
					break;
				}
			}
			if (!c) f = 0;
		}
		ans += f;
		puts(f ? "Connected" : "Disconnected");
	}
}
