#include <cstdio>
#include <vector>
const int L = 1e5 + 10;
int m, ch[L][26], fail[L], q[L], h, t, dfn[L], sz[L], clk, lines, pos[L], ans[L], trie_cnt, a[L];
std::vector<int> to[L];
struct QU{int x, id;};
std::vector<QU> qu[L];
char s[L];
inline int lowbit(int x) {return x&-x;}
inline void add(int p, int v) {for (;p <= clk; p += lowbit(p)) a[p] += v;}
inline int pre(int p) {
	int s = 0;
	for (;p; p -= lowbit(p)) s += a[p];
	return s;
}
inline int sum(int l, int r) {return pre(r) - pre(l - 1);}
int init(int u) {
	dfn[u] = ++clk;
	for (int i = 0; i < (int)to[u].size(); i++)
		sz[u] += init(to[u][i]);
	return sz[u] += 1;
}
void dfs(int u) {
	add(dfn[u], 1);
	for (int i = 0; i < (int)qu[u].size(); i++) {
		QU& qq = qu[u][i];
		ans[qq.id] = sum(dfn[qq.x], dfn[qq.x] + sz[qq.x] - 1);
	}
	for (int i = 0; i < 26; i++) if (ch[u][i]) dfs(ch[u][i]);
	add(dfn[u], -1);
}
int main() {
	freopen("noi2011_type.in", "r", stdin);
	freopen("noi2011_type.out", "w", stdout);
	scanf("%s", s);
	int now = 0;
	q[t++] = now;
	for (char* p = s; *p; p++) {
		if (*p == 'P') pos[++lines] = now;
		else if (*p == 'B') now = q[--t];	
		else {
			if (!ch[now][*p - 'a']) ch[now][*p - 'a'] = ++trie_cnt;
			q[t++] = now;
			now = ch[now][*p - 'a'];
		}
	}
	t = 0;
	for (int i = 0; i < 26; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int x = q[h++];
		to[fail[x]].push_back(x);
		for (int i = 0; i < 26; i++) if (ch[x][i]) {
			q[t++] = ch[x][i];
			int p = fail[x];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[x][i]] = ch[p][i];
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x, y;scanf("%d%d", &x, &y);
		x = pos[x], y = pos[y];
		qu[y].push_back((QU){x, i});
	}
	init(0), dfs(0);
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
