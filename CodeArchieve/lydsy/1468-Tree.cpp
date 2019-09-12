#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#define foredge for (int e = hed[u], v; v = st[e].v, e; e = nxt[e]) 
using std::max;
namespace I {
	const int L = 1 << 15;
	char a[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s=a) + fread(a, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int ch = gc(), s = 0;
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) s = s*10 + ch - '0', ch = gc();
		return s;
	}
}using I::gi;
const int V = 4e4 + 10, E = V << 1;
struct EDGE{int u, v, w;}st[E];
int n, k, hed[V], nxt[E], sz[V], d[V], in[V], ans;
bool rm[V];
inline void ad(int u, int v, int w) {
	static int sz = 0;
	st[++sz]=(EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w) {
	ad(u, v, w), ad(v, u, w);
}
std::vector<int> dd;
void dfs(int u, int fa) {
	foredge if (!rm[v] && v != fa) 
		dd.push_back(d[v] = d[u] + st[e].w), dfs(v, u);
}
int size(int u, int fa) {
	sz[u] = 1;
	foredge if (!rm[v] && v != fa) sz[u] += size(v, u);
	return sz[u];
}
void cent(int& u) {
	int tot = size(u, 0), mxs = u, fa;
	do {
		fa = u;
		u = mxs;
		mxs = 0;
		foredge if (!rm[v] && sz[v] > sz[mxs] && v != fa) mxs = v;
	} while (sz[mxs] > tot/2);
}
int count(int u, int l) {
	dd.clear();
	dd.push_back(d[u] = l);
	dfs(u, 0);
	std::sort(dd.begin(), dd.end());
	int s = 0;
	for (int i = 0, j = dd.size() - 1; i < j; i++) {
		while (i < j && dd[i] + dd[j] > k) j--;
		s += j - i;
	}
	return s;
}
int sol(int u) {
	cent(u);
	int r = count(u, 0);
	rm[u] = 1;
	foredge if (!rm[v]) r -= count(v, st[e].w);
	foredge if (!rm[v]) r += sol(v);
	return r;
}
int main() {
//	freopen("input", "r", stdin);
	n = gi();
	for (int i = 1; i < n; i++) {
		int x = gi(), y=gi(), w = gi();
		add(x, y, w);
	}
	k = gi();
	printf("%d", sol(1));
}
