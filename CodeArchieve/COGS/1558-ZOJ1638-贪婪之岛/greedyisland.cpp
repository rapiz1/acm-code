#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <queue>
#define file(x) "greedyisland." #x
const int N = 1e5 + 10, V = 400, E = V << 3, BASE = 1e5;
namespace I {
	const int L = 1 << 15 | 1;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf ,1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int r = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
		return r;
	}
}using I::gi;
int T; 
struct C{
	int w[4];
	bool operator<(const C& rhs)const {return w[T] > rhs.w[T];}
}ca[N];
struct EDGE{int u, v, w, c, f;}st[E];
int n, li[3], hed[V], nxt[E], sz, s, t; 
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
std::queue<int> q;
int dis[V], p[V], a[V];
bool inq[V];
inline bool spfa(int& cost) {
	memset(dis, 0x3f, sizeof(dis));
	q.push(s);
	p[s] = dis[s] = 0;
	a[s] = 0x3f3f3f3f;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			p[v] = e;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[t] == 0x3f3f3f3f) return 0;
	for (int e = p[t]; e; e = p[st[e].u]) {
		cost += st[e].w*a[t];
		st[e].f += a[t], st[e^1].f -= a[t];
	}
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	int ks = gi();
	while (ks--) {
		memset(hed, 0, sizeof(hed));
		memset(nxt, 0, sizeof(nxt));
		memset(st, 0, sizeof(st));
		memset(ca, 0, sizeof(ca));
		sz = 1;
		n = gi(), li[0] = gi(), li[1] = gi(), li[2] = gi();
		for (int i = 1; i <= n; i++) {
			int tot = 0;
			for (int j = 0; j < 3; j++) tot += ca[i].w[j] = gi();
			for (int j = 0; j < 3; j++) ca[i].w[j] = ca[i].w[j]*BASE + tot;
		}
		for (int i = 0; i < 3; i++) {
			T = i, std::sort(ca + 1, ca + 1 + n);
			int tot = std::min(li[0] + li[1] + li[2], n);
			for (int j = 1; j <= tot; j++) ca[j].w[3] = 1; 
		}
		T = 3, std::sort(ca + 1, ca + 1 + n);
		for (n = 0; ca[n + 1].w[3]; n++);
		s = n + 1, t = n + 2;
		for (int i = 1; i <= n; i++) {
			add(s, i, 0, 1);
			for (int j = 0; j < 3; j++) add(i, n + 3 + j, -ca[i].w[j], 1);
		}
		for (int j = 0; j < 3; j++) add(n + 3 + j, t, 0, li[j]);
		int cost = 0, sum = 0;
		while (spfa(cost)) ;
		for (int i = 2; i <= sz; i++) if (st[i].u == s && st[i].c == st[i].f) {
			int j = st[i].v;
			for (int k = 0; k < 3; k++) sum += ca[j].w[k];
		}
		printf("%d %d\n", -cost/BASE, -cost%BASE);
	}
}
