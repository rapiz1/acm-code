#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cmath>
namespace I {
	const int L = 1 << 15 | 1;
	char*s, *t, buf[L];
	inline char gc() {
		if (s == t) t = (s=buf)+fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int x = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x = x*10 + ch - '0', ch = gc();
		return x;
	}
}using I::gi;
const int N = 5e4 + 10, K = 17;
int n, m, a[N], mc, qc, bks, pre[N], anc[N][K], dep[N], ans[N], bc[N], cnt[N], bk, clk;
bool in[N];
std::vector<int> to[N];
struct Query {int t, u, v;
	bool operator<(const Query& rhs)const {
		if (pre[u]/bks != pre[rhs.u]/bks) return pre[u]/bks < pre[rhs.u]/bks;
		else if (pre[v]/bks != pre[rhs.v]/bks) return pre[v]/bks < pre[rhs.v]/bks;
		else return t < rhs.t;
	}
}qu[N];
struct Modi {
	int t, x, from, to;
}modi[N];
void dfs(int u) {
	pre[u] = ++clk;
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i-1]][i-1];
	for (int i =0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == anc[u][0]) continue;
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v);
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int x = dep[u] - dep[v], i = 0; x; x>>=1, i++) if (x&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v=  anc[v][i];
	return u == v ? u : anc[u][0];
}
inline void flip(int u) {
	if (a[u] > n) return;
	if (in[u]) {
		if (!--cnt[a[u]]) bc[a[u]/bk]--;
	}
	else {
		if (!cnt[a[u]]++) bc[a[u]/bk]++;
	}
	in[u]^=1;
}
inline void move(int u, int v) {
	for(;u!=v;u=anc[u][0]) {
		if (dep[u] < dep[v]) std::swap(u, v);
		flip(u);
	}
}
inline int mex() {
	int i;
	for (i = 0; i <= n/bk; i++) if (bc[i] != bk) break;
	for (int j = i*bk; j <= n; j++) if (!cnt[j]) return j;
	return -1;
}
inline void movet(int t, int k) {
	if (in[modi[t].x]) {
		flip(modi[t].x);
		a[modi[t].x] = k ? modi[t].to : modi[t].from;
		flip(modi[t].x);
	}
	else a[modi[t].x] = k ? modi[t].to : modi[t].from;
}
int main() {
//	freopen("input", "r", stdin);
	n=gi(),m=gi();
	for (int i = 1; i<= n; i++) a[i]=gi();
	for (int i = 1, u, v; i < n; i++) u=gi(),v=gi(), to[u].push_back(v), to[v].push_back(u);
	dfs(1);
	for (int i = 1; i <= m; i++) {
		int t=gi(), u=gi(), v=gi();
		t^=1;
		if (t) {
			modi[++mc] = (Modi){i, u, a[u], v};
			a[u] = v;
		}
		else {
			if (pre[u] > pre[v]) std::swap(u, v);
			qu[++qc] = (Query){i, u, v};
		}
	}
	bks = pow(n, 2.0/3);
	bk = sqrt(n);
	std::sort(qu + 1, qu + 1 + qc);
	int t = mc, l = 1, r = 1;
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1; i <= qc; i++) {
		int lca = ::lca(qu[i].u, qu[i].v);
		move(l, qu[i].u); l = qu[i].u;
		move(r, qu[i].v); r = qu[i].v;
		while (t+1 <= mc && modi[t+1].t<qu[i].t) movet(++t, 1);
		while (modi[t].t>qu[i].t) movet(t--, 0);
		flip(lca);
		ans[qu[i].t] = mex();
		flip(lca);
	}
	for (int i = 1; i <= n; i++) if (ans[i] <= n) printf("%d\n", ans[i]);
}
