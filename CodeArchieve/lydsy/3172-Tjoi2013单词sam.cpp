#include <cstdio>
#include <cstring>
#include <vector>
const int N = 3e6;
int n, len, sz = 1, pre[N], nxt[N][27], ri[N], start[210], end[210], last = 1, val[N];
char s[N];
std::vector<int> to[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	val[np] = val[p] + 1;
	ri[np]++;
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
int dfs(int p) {
	for (int i = 0; i < to[p].size(); i++) ri[p] += dfs(to[p][i]);
	return ri[p];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		start[i] = len;
		scanf("%s", s + len);
		end[i] = (len += strlen(s + len));
		for (int j = start[i]; j < end[i]; j++) extend(s[j] - 'a');
		extend(26);
	}
	for (int i = 1; i <= sz; i++) to[pre[i]].push_back(i);
	dfs(1);
	for (int i = 1; i <= n; i++) {
		int p, j;
		for (p = 1, j = start[i]; j < end[i]; j++) {
			int c = s[j] - 'a';
			p = nxt[p][c];
		}
		printf("%d\n", ri[p]);
	}
}
