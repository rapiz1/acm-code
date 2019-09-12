#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1110010*2;
int n, m, f[N], nxt[N][2], pre[N], val[N], last = 1, sz = 1;
char s[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			pre[nq] = pre[q], val[nq] = val[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	} else pre[np] = 1;
	last = np;
}
bool check(int l) {
	static int t, q[N];
	t = 0;
	for (int i = 1, len = 0, p = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (i - l >= 0) {
			while (t && f[q[t - 1]] - q[t - 1] < f[i - l] - (i - l)) t--;
			q[t++] = i - l;
		}
		int c = s[i] - '0';
		for(;p&&!nxt[p][c]; p = pre[p]);
		if (nxt[p][c]) len = std::min(len + 1, val[p] + 1), p = nxt[p][c];
		else len = 0, p = 1;
		if (t) {
			int pos = std::lower_bound(q, q + t, i - len) - q, j = q[pos];
			if (pos != t) f[i] = std::max(f[i], f[j] - j + i);
		}
	}
	return 10*f[n] >= n*9;
}
inline void solve() {
	scanf("%s", s + 1);
	int l = 0, r = strlen(s + 1);
	n = r;
	while (l < r) {
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
int main() {
	//freopen("ctsc2012_cheat.in", "r", stdin);
	//freopen("ctsc2012_cheat.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		last = 1;
		for (int j = 0; s[j]; j++) extend(s[j] - '0');
	}
	while (m--) solve();
}
