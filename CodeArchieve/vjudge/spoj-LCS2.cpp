#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
const int N = 200010;
int n, pre[N], nxt[N][26], val[N], match[N], ans[N], sz = 1, last = 1;
char s[N];
inline void extend(int c) {
	int np = ++sz, p = last;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[np] = nq, pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s);
	for (int i = 0; s[i]; i++) extend(s[i] - 'a');
	memset(ans, 0x3f, sizeof(ans));
	while (scanf("%s", s) == 1) {
		memset(match, 0, sizeof(match));
		int p = 1, l = 0;
		for (int j = 0; s[j]; j++) {
			int c = s[j] - 'a';
			for (;p&&!nxt[p][c]; p = pre[p], match[p] = val[p]);
			if (nxt[p][c]) l = std::min(l + 1, val[p] + 1), p = nxt[p][c];
			else p = 1, l = 0;
			match[p] = std::max(match[p], l);
		}
		for (int i = 1; i <= sz; i++) ans[i] = std::min(ans[i], match[i]);
	}
	int res = 0;
	for (int i = 2; i <= sz; i++) if (ans[i] != 0x3f3f3f3f) res = std::max(res, ans[i]);
	printf("%d\n", res);
}
