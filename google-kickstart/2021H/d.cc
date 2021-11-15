#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N = 2e5 + 10;
static const int DEP = 23;
static const int MOD = 1e9 + 7;

int qpow(ll b, ll r) {
  ll ret = 1;
  for (ll x = b; r; r >>= 1, x = (x * x) % MOD) {
    if (r & 1) ret = (ret * x) % MOD;
  }
  return ret;
}
int modrev(int x) { return qpow(x, MOD - 2); }

struct Edge {
  int u, v;
  ll pt, pf;
};
vector<Edge> to[N];
vector<Edge> pedge;
int n, q, dep[N], fa[N][DEP];
vector<ll> truep;  // node 1..n
// chainpt is inclusive
void dfs(int u) {
  if (u != 1) {
    int par = fa[u][0];
    dep[u] = dep[fa[u][0]] + 1;

    truep[u] = (truep[par] * pedge[u].pt % MOD +
                (1 - truep[par] + MOD) % MOD * pedge[u].pf % MOD) %
               MOD;

    for (int d = 1; d < DEP; d++) {
      fa[u][d] = fa[fa[u][d - 1]][d - 1];
    }
  }

  for (auto e : to[u]) {
    int v = e.v;
    dfs(v);
  }
}

int lca(int u, int v) {
  while (dep[u] != dep[v]) {
    if (dep[u] > dep[v]) swap(u, v);  // dep[u] < dep[v]
    v = fa[v][0];
  }
  while (u != v) u = fa[u][0], v = fa[v][0];
  return u;
}

/*
int getone() {
  ll x = 1e6;
  return x * modrev(x) % MOD;
}*/

vector<ll> calc(int u, int root) {
  vector<Edge> path;
  vector<ll> ans = {1, 1};  // A|D, A|neg D
  if (u == root) return ans;
  for (int x = u; x != root; x = fa[x][0]) path.push_back(pedge[x]);
  ans[0] = path.rbegin()->pt;
  ans[1] = path.rbegin()->pf;
  for (int i = path.size() - 2; i >= 0; i--) {
    auto bk = ans;
    ans[0] =
        bk[0] * path[i].pt % MOD + (1 - bk[0] + MOD) % MOD * path[i].pf % MOD;
    ans[1] =
        bk[1] * path[i].pt % MOD + (1 - bk[1] + MOD) % MOD * path[i].pf % MOD;
    ans[0] %= MOD;
    ans[1] %= MOD;
  }
  return ans;
}

void solve() {
  ll roott;
  cin >> n >> q >> roott;
  roott = roott * modrev(1e6) % MOD;
  to[1].clear();

  pedge.clear();
  pedge.resize(n + 1);
  truep.clear();
  truep.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    to[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int nfa;
    ll pt, pf;
    cin >> nfa >> pt >> pf;
    pt = pt * modrev(1e6) % MOD;
    pf = pf * modrev(1e6) % MOD;
    auto e = Edge{nfa, i, pt, pf};
    to[nfa].push_back(e);
    pedge[i] = e;

    // memset(fa[i], 0, sizeof fa[i]);
    fa[i][0] = nfa;
  }
  pedge[1] = Edge{0, 1, roott, roott};
  truep[1] = roott;

  dfs(1);
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    int l = lca(u, v);
    ll ans = 0;
    auto up = calc(u, l);
    auto vp = calc(v, l);
    ans = up[0] * vp[0] % MOD * truep[l] % MOD;
    if (l != u && l != v)
      ans = (ans + up[1] * vp[1] % MOD * (1 - truep[l] + MOD) % MOD) % MOD;
    ans %= MOD;
    cout << ans;
    cout << " ";
  }
}
int main() {
  assert(qpow(3, 7) == 2187);
  assert(8848LL * modrev(8848) % MOD == 1);
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: ", i);
    solve();
    putchar('\n');
  }
}
