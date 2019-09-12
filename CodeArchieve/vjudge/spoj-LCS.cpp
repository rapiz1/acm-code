#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
const int N = 250010*2;
int last = 1, sz = 1, nxt[N][26], pre[N], val[N], n, ans;
char s[N];
void extend(int c) {
	int np = ++sz, p = last;
	val[np] = val[p] + 1; 
	for(;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[nq] = pre[q], pre[np] = nq, pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) extend(s[i] - 'a');
	scanf("%s", s);
	n = strlen(s);
	int p = 1, l = 0;
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		for (;p&&!nxt[p][c]; p = pre[p], assert(l>=val[p])) ;
		if (nxt[p][c])  l = std::min(l + 1, val[p] + 1), p = nxt[p][c];
		else l = 0, p = 1;
		ans = std::max(ans, l);
	}
	printf("%d\n", ans);
}
