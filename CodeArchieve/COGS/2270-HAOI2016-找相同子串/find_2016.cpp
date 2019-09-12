#include <cstdio>
#include <cstring>
#include <vector>
#define file(x) "find_2016."#x
const int N = 8e5 + 10;
int sz = 1, ri[N][2], pre[N], nxt[N][26], val[N], last = 1, T;
long long ans;
char s[N];
std::vector<int> to[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	ri[np][T]++;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			pre[nq] = pre[q], val[nq] = val[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[np] = pre[q] = nq;	
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] =  nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
void dfs(int u) {
	for (int i = 0; i < to[u].size(); i++) {
		int v = to[u][i];
		dfs(v);
		ri[u][0] += ri[v][0], ri[u][1] += ri[v][1];
	}
	ans += ri[u][0]*1ll*ri[u][1]*(val[u] - val[pre[u]]);
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%s", s);
	for (int i = 0; s[i]; i++) extend(s[i] - 'a');
	T = last = 1;
	scanf("%s", s);
	for (int i = 0; s[i]; i++) extend(s[i] - 'a');
	for (int i = 1; i <= sz; i++) to[pre[i]].push_back(i);
	dfs(1);
	printf("%lld\n", ans);
}
