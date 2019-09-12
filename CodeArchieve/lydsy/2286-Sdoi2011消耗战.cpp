#include <cstdio>
#include <algorithm>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
typedef long long ll;
const int V = 25e4 + 10, E = V << 1, K = 20;
int anc[V][K], dep[V], n, m, k, kk, dfn[V], clk, ver[V], sk[V], top;
ll val[V];
struct Graph {
    int hed[V], nxt[E], sz;
    struct Edge{int u, v, w;}st[E];
    inline void add(int u, int v, int w) {
        st[++sz] = (Edge){u, v, w};
        nxt[sz] = hed[u], hed[u] = sz;
    }
    inline void clear() {
        for (int i = 1; i <= sz; i++) st[i] = (Edge){0, 0, 0};
        sz = 0;
        for (int i = 1; i <= kk; i++) hed[ver[i]] = 0;
    }
    void dfs(int u) {
        dfn[u] = ++clk;
        for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
        fore if (v != anc[u][0]) {
            dep[v] = dep[u] + 1;
            anc[v][0] = u;
            val[v] = std::min(val[u], (ll)st[e].w);
            dfs(v);
        }
    }
    inline void init() {
        scanf("%d", &n);
        for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d", &u, &v, &w), add(u, v , w), add(v, u, w);
        val[1] = 1ll << 60;
        dfs(1);
    }
    ll dp(int u) {
        ll f = 0;
        int ch = 0;
        fore f += dp(v), ch++;
        return ch ? std::min(f, (ll)val[u]) : val[u];
    }
}g, vir;
inline int cmp(int a, int b) {return dfn[a] < dfn[b];}
inline int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int x = dep[u] - dep[v], i = 0; x; x>>=1, i++) if (x&1) u = anc[u][i]; 
    for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    return u == v ? u : anc[u][0];
}
int main() {
//  freopen("input", "r", stdin);
    g.init();
    scanf("%d", &m);
    while (m--) {
        vir.clear();
        scanf("%d", &k);
        kk = k;
        for (int i = 1; i <= k; i++) scanf("%d", ver + i);
        std::sort(ver + 1, ver + 1 + k, cmp);
        top = 0;
        sk[++top] = 1;
        for (int i = 1; i <= k; i++) {
            int u = ver[i], v = sk[top], w = lca(u, v);
            if (w == v) sk[++top] = u;
            else {
                while (top >= 2 && dep[sk[top - 1]] >= dep[w]) {
                    vir.add(sk[top - 1], sk[top], 0);
                    top--;
                } 
                if (sk[top] != w) {
                    vir.add(w, sk[top--], 0);
                    ver[++kk] = w;
                    sk[++top] = w;
                }
                sk[++top] = u;
            }
        }
        for (;top > 1;top--) vir.add(sk[top - 1], sk[top], 0);
        ver[++kk] = 1;
				for (int i = 1; i <= k; i++) vir.hed[ver[i]] = 0;
        printf("%lld\n", vir.dp(1));
    }
}
