#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
const int N = 1e5 + 10;
int n, m, l[N], rt;
long long ans, s[N];
std::priority_queue<int>* st[N];
std::vector<int> to[N];
void dfs(int u) {
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v;
		dfs(v=to[u][i]);
		if (st[v]->size() > st[u]->size()) swap(st[u], st[v]);
		while (!st[v]->empty()) {
			int x = st[v]->top(); st[v]->pop();
			st[u]->push(x);
		}
		s[u] += s[v];
		delete st[v];
	}
	while (s[u] > m) s[u] -= st[u]->top(), st[u]->pop();
	ans = std::max(ans, (long long)st[u]->size()*l[u]);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d%lld%d", &x, &s[i], &l[i]);
		st[i] = new std::priority_queue<int>;
		st[i]->push(s[i]);
		to[x].push_back(i);
		if (x == 0) rt = i;
	}
	dfs(rt);
	printf("%lld\n", ans);
}
