#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], sz[N], id[N], cnt;
stack<int> s;
bool ins[N];
int dfs(int x) {
	if (b[x]) return b[x];
	ins[x] = 1;
	s.push(x);
	if (ins[a[x]]) {
		int t;
		++cnt;
		do {
			t = s.top();s.pop();
			ins[t] = 0;
			id[t] = cnt;
			sz[cnt]++;
		}while (a[x] != t);
		return sz[id[x]];
	}
	else {
		b[x] = dfs(a[x]);
		if (!id[x]) b[x]++;
		return b[x];
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = id[i] = sz[i] = 0;
		for (int i = 1; i <= n; i++) {
			dfs(a[i]);
			while (!s.empty()) {
				int x = s.top();s.pop();
				ins[x] = 0;
			}
		}
		for (int i = 1; i <= n; i++) ans = std::max(ans, b[i]);
		for (int i = 1; i <= cnt; i++) ans = std::max(ans, sz[i]);
		printf("%d\n", ans);
	}
}
