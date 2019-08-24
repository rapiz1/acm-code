#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 2*N;
std::vector<int> to[N];
int n, q;
long long av[N], ans[N];
void dfs(int u, int fa) {
  ans[u] = av[u] + ans[fa];
  for (auto v: to[u]) if (v != fa) {
    dfs(v, u);
  }
}
int main() {
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  for (int i = 1; i <= q; i++) {
    int pos, value;
    cin >> pos >> value;
    av[pos] += value;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) 
    cout << ans[i] << " ";
}
