#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <algorithm>
#define lch (o<<1)
#define rch (o<<1|1)
#define mid ((l+r)>>1)
namespace I{ 
	const int L = 1 << 15 | 1;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s=buf)+fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int x = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch))x=x*10+ch-'0', ch = gc();
		return x;
	}
}using I::gi;
const int N = 5010, V = 2e4 + N, E = 1e6, W = 5000;
int n, hed[V], nxt[E], sz = 1, S, T, a[V], p[V], dis[V], tot, ans, L=5000, R=1, l[N], r[N], c[N], in[V], count;
bool inq[V];
struct Edge{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (Edge){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {
	_add(u, v, w, c), _add(v, u, -w, 0);
}
void build(int o, int l, int r) {
	if (l == r) {
		add(o, T, 0, 1);
		return;
	}
	build(lch, l, mid);
	build(rch, mid+1, r);
	add(o, lch, 0, 1e9);
	add(o, rch, 0, 1e9);
}
void change(int o, int l, int r, int q1, int q2) {
	if (!in[o]++) count++;
	if (q1 <= l && r <= q2) {
		add(tot, o, 0, 1);
		return;
	}
	if (q1 <= mid) change(lch, l, mid, q1, q2);
	if (mid < q2) change(rch, mid + 1, r, q1, q2);
}
std::queue<int> q;
inline bool spfa() {
	memset(dis, 0x3f, sizeof dis);
	q.push(S);
	inq[S] = 1;
	dis[S] = 0;
	a[S] = 1e9;
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = st[e].w + dis[u];
			p[v] = e;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[T] == 0x3f3f3f3f) return 0;
	for (int e = p[T]; e; e = p[st[e].u]) {
		ans += st[e].w*a[T];
		st[e].f += a[T];
		st[e^1].f -= a[T];
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	n =gi();
	S = 4*W + 1, T = S + 1;
	tot = T;
	for (int i = 1; i <= n; i++) l[i] = gi()+1, r[i] = gi(), c[i] = gi(), L = std::min(L, l[i]), R = std::max(R, r[i]);
	build(1, L, R);
	for (int i = 1; i <= n; i++) {
		add(S, ++tot, -c[i], 1);
		change(1, L, R, l[i], r[i]);
	}
	while (spfa()) ;
	printf("%d\n", -ans);
}
