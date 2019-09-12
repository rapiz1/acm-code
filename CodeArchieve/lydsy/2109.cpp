#include <cstdio>
#include <queue>
#include <vector>
const int N = 2e3 + 10;
int n, m, t[N], de[N], dd[N];
struct CMP {
	bool operator()(int a, int b) {return n - t[a] > n - t[b];}
};
std::priority_queue<int, std::vector<int>, CMP> q;
std::vector<int> to[N];
void work(int s) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (i != s && !de[i]) {
		q.push(i);
	}
	while (!q.empty()) {
		int u = q.top(); q.pop();
		if (cnt < n - t[u]) continue;
		cnt++;
		for (int i = 0; i < (int)to[u].size(); i++) {
			int v = to[u][i];
			de[v]--;
			if (!de[v] && v != s) q.push(v);
		}
	}
	printf("%d ", n - cnt);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", t + i);
	for (int i = 1;i <= m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		to[b].push_back(a);
		dd[a]++;
	}
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) de[j] = dd[j];
		work(i);
	}
}
