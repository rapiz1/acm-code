#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define file(x) "savour."#x
const int N = 6e5 + 10;
typedef long long ll;
int n, last = 1, sz = 1, nxt[N][26], pre[N], val[N];
char s[N];
ll a[N], way[N], wei[N], ri[N], mx[N], mn[N], MX, MN;
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
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			pre[q] = nq, pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
int dfs(int p) {
	for (int i = 0; i < to[p].size(); i++) {
		int v = to[p][i];
		dfs(v);
		way[val[p]] += ri[p]*ri[v];
		if (mn[v] != MN) {
			if (mn[p] != MN) wei[val[p]] = std::max(wei[val[p]], mn[p]*mn[v]);
			mn[p] = std::min(mn[p], mn[v]);
		}
		if (mx[v] != MX) {
			if (mx[p] != MX) wei[val[p]] = std::max(wei[val[p]], mx[p]*mx[v]);
			mx[p] = std::max(mx[p], mx[v]);
		}
		ri[p] += ri[v];
	}
	return ri[p];
}
int main() {
	memset(mn,0x3f, sizeof mn);
	MN = mn[0];
	memset(mx, 0xc0, sizeof mx);
	memset(wei, 0xc0, sizeof(wei));
	MX = mx[0];
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = n; i; i--) mx[sz + 1] = mn[sz + 1] = a[i], extend(s[i] - 'a');
	for (int i = 1; i <= sz; i++) to[pre[i]].push_back(i);
	dfs(1);
	for (int i = n - 1; i >= 0; i--) way[i] += way[i + 1], wei[i] = std::max(wei[i], wei[i + 1]);
	for (int i = 0; i < n; i++) printf("%lld %lld\n", way[i], wei[i] == wei[N - 1] ? 0 : wei[i]);
}
