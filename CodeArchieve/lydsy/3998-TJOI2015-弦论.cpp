#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1e6 + 10;
int n, top = 1, last = 1, pre[N], nxt[N][26], val[N];
long long ri[N], sz[N];
char s[N];
inline void extend(int c) {
	int p = last, np = ++top;
	val[np] = val[p] + 1;
	ri[np]++;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++top;
			val[nq] = val[p] + 1;
			pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[np] = pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
long long dfs(int p) {
	if (sz[p]) return sz[p];
	for (int i = 0; i < 26; i++) if (nxt[p][i]) sz[p] += dfs(nxt[p][i]);
	return sz[p] += ri[p];
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s);
	for (int i = 0; s[i]; i++) extend(s[i] - 'a');
	int t, k;
	scanf("%d%d", &t, &k);
	if (t) {
		static int qu[N], cc[N];
		for (int i = 1; i <= top; i++) cc[val[i]]++;
		for (int i = 1; i <= top; i++) cc[i] += cc[i - 1];
		for (int i = top; i; i--) qu[cc[val[i]]--] = i;
		for (int i = top; i; i--) ri[pre[qu[i]]] += ri[qu[i]];
	}
	else for (int i = 1; i <= top; i++) ri[i] = 1;
	dfs(1);
	if (k > sz[1]) puts("-1");
	else for (int p = 1;k;) {
		for (int c = 0; c < 26; c++) if (nxt[p][c]) {
			if (k <= sz[nxt[p][c]]) {
				k -= std::min((long long)k, ri[nxt[p][c]]);
				putchar(c + 'a');
				p = nxt[p][c];
				break;
			}
			else k -= sz[nxt[p][c]];
		}
	}
}
