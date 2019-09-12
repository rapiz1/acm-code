#include <cstdio>
#include <vector>
#include <stack>
const int N = 1010;
int n, cnt, b, be[N], cap[N]; 
std::vector<int> to[N];
std::stack<int> st;
void dfs(int u, int fa) {
	int bd = st.size();
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa) continue;
		dfs(v, u);
		if ((int)st.size() - bd >= b) {
			++cnt;
			while ((int)st.size() > bd) {
				int x = st.top(); st.pop();
				be[x] = cnt;
			} 
			cap[cnt] = u;
		}
	}
	st.push(u);
}
int main() {
	scanf("%d%d", &n, &b);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	} 
	dfs(1, 0);
	while (!st.empty()) {
		int x = st.top(); st.pop();
		be[x] = cnt;
	}
	printf("%d\n", cnt);
	if (!cnt) return 0;
	for (int i = 1; i <= n; i++) printf("%d ", be[i]);
	puts("");
	for (int i = 1; i <= cnt; i++) printf("%d ", cap[i]);
}
