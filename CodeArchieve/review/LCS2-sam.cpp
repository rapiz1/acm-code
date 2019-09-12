#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2e5 + 10, C = 'z' - 'a' + 1;
int top = 1, nxt[N][C], pre[N], mat[N], ans[N], last = 1, val[N];
char s[N];
void extend(int c) {
	int np = ++top, p = last;
	val[np] = val[p] + 1;
	for(;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++top;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[nq] = pre[q];
			val[nq] = val[p] + 1;
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s);
	for (int i = 0;s[i]; i++) extend(s[i] - 'a');
	memset(ans, 0x3f, sizeof ans);
	while (scanf("%s", s) == 1) {
		memset(mat, 0, sizeof mat);
		for(int i = 0, p = 1, l = 0; s[i]; i++) {
			int c = s[i] - 'a';
			for(;p&&!nxt[p][c]; p = pre[p], mat[p] = val[p]);
			if (nxt[p][c]) l = std::min(l + 1, val[p] + 1), p = nxt[p][c];
			else p = 1, l = 0;
			mat[p] = std::max(mat[p], l);
		}
		for (int i = 1; i <= top; i++) ans[i] = std::min(ans[i], mat[i]);
	}
	int ret = 0;
	for (int i = 1; i <= top; i++) if (ans[i] != 0x3f3f3f3f) ret = std::max(ret, ans[i]);
	printf("%d\n", ret);
}
