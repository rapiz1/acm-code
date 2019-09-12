#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
const int N = 1e5 + 10;
int n, sz = 1, last = 1, nxt[N][26], pre[N], val[N], ans;
std::vector<int> to[N];
std::set<int> stt[N];
typedef std::set<int>::iterator IT;
char s[N];
inline void extend(int c) {
	int p = last, np = last = ++sz;
	val[np] = val[p] + 1;
	for(;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[nq] = pre[q], val[nq] = val[p] + 1;
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
}
inline void upd(int l, int x, int y) {
	if (x > y) std::swap(x, y);
	int p = y - x;
	ans = std::max(ans, (l + p)/p);
}
void dfs(int p) {
	for (int i = 0; i < (int)to[p].size(); i++) {
		int v = to[p][i];
		dfs(v);
		if (stt[v].size() > stt[p].size()) std::swap(stt[v], stt[p]);
		for (IT it = stt[v].begin(); it != stt[v].end(); it++) {
			IT pp = stt[p].find(*it);
			if (pp != stt[p].begin()) upd(val[p], *--pp, *it);
			pp = stt[p].find(*it);
			if (++pp != stt[p].end()) upd(val[p], *--pp, *it);
			stt[p].insert(*it);
		}
	}
}
void solve() {
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s + i);
	for (int i = 1; s[i]; i++) extend(s[i] - 'a'), stt[last].insert(i);
	for (int i = 1; i <= sz; i++) to[pre[i]].push_back(i);
	dfs(1);
	memset(pre, 0, sizeof pre);
	memset(nxt, 0, sizeof nxt);
	memset(val, 0, sizeof val);
	for (int i = 1; i <= sz; i++) stt[i].clear(), to[i].clear();
	sz = last = 1;
	printf("%d\n", ans);
}
int main() {
//	freopen("input", "r", stdin);
	int ks;
	scanf("%d", &ks);
	while (ks--) solve();
}
