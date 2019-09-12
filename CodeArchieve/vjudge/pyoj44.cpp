#include <cstdio>
#include <cctype>
#include <vector>
namespace I {
	const int L = 1 << 15|1;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s=buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int r = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
		return r;
	}
}using I::gc;using I::gi;
const int M = 15e5 + 10, N = 1e6 + 10;
int n, m, rt[M], vc = 1, a[N], qu, ans[M];
std::vector<int> to[M];
struct OP {
	int x, y, t, id;
}op[M];
inline int lowbit(int x) {return x&-x;}
inline void add(int p, int x) {
	for (;p<= n; p+=lowbit(p)) a[p] += x;
}
inline int pre(int p) {
	int ret = 0;
	for(;p;p -= lowbit(p)) ret += a[p];
	return ret;
}
void dfs(int u) {
	if (op[u].t == 'Q') ans[op[u].id] = pre(op[u].y) - pre(op[u].x - 1);
	else if (op[u].t == 'A') add(op[u].x, op[u].y);
	for (int i = 0; i < (int)to[u].size(); i++) {
		dfs(to[u][i]);
	}
	if (op[u].t == 'A') add(op[u].x, -op[u].y);
}
int main() {
//	freopen("input", "r", stdin);
	n = gi(), m = gi();
	for (int i = 1; i <= m; i++) {
		char cmd = gc();
		int v = gi();
		if (cmd == 'C') rt[++vc] = rt[v];
		else {
			int x = gi(), y = gi();
			op[i] = {x, y, cmd, cmd == 'Q' ? ++qu : 0};
			to[rt[v]].push_back(i);
			rt[v] = i;
		}
	}
	dfs(0);
	for (int i = 1; i <= qu; i++) printf("%d\n", ans[i]);
}
