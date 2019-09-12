#include <cstdio>
#include <cstring>
const int N = 2e5;
int n, nxt[N][26], pre[N], val[N], last = 1, sz = 1, cnt, ri[N];
char s[N], now[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[q] = nq, pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}else pre[np] = 1;
	last = np;
}
int dfs(int u) {
	if (ri[u]) return ri[u];
	for (int i = 0; i < 26; i++) if (nxt[u][i]) ri[u] += dfs(nxt[u][i]);
	return ++ri[u];
}
int main() {
	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) extend(s[i] - 'a');
	dfs(1);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x;scanf("%d", &x);
		int p = 1;
		cnt = 0;
		while (x) {
			for (int i = 0; i < 26; i++) if (nxt[p][i]) {
				if (x <= ri[nxt[p][i]]) {
					x--;
					now[cnt++] = 'a' + i;
					p = nxt[p][i];
					break;
				}
				else x -= ri[nxt[p][i]];
			}
		}
		for (int i = 0; i < cnt; i++) putchar(now[i]);
		putchar('\n');
	}
}
