#include <cstdio>
#include <cstring>
const int N = 2e5 + 10;
int n, k, sz = 1, last = 1, pre[N], nxt[N][26], val[N], id[N], end[N], cnt[N];
long long ww[N];
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
			pre[nq] = pre[q];
			val[nq] = val[p] + 1;
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[q] = pre[np] = nq;
			for (;p&&nxt[p][c] == q;p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + end[i - 1]);
		end[i] = end[i - 1] + strlen(s + end[i - 1]);
		last = 1;
		for (int j = end[i - 1]; j < end[i]; j++) extend(s[j] - 'a');
	}
	for (int i = 1; i <= n; i++) {
		for (int j = end[i - 1], p = 1; j <= end[i]; p = nxt[p][s[j++] - 'a']) {
			for (int x = p; x && id[x] != i; x = pre[x]) id[x] = i, cnt[x]++;
		}
	}
	static int qu[N], cc[N];
	for (int i = 1; i <= sz; i++) cc[val[i]]++;
	for (int i = 1; i <= sz; i++) cc[i] += cc[i - 1];
	for (int i = sz; i; i--) qu[cc[val[i]]--] = i;
	for (int i = 1; i <= sz; i++) 
		ww[qu[i]] = (cnt[qu[i]] >= k)*(val[qu[i]] - val[pre[qu[i]]]) + ww[pre[qu[i]]]; 
	for (int i = 1; i <= n; i++) {
		long long ans = 0;
		for (int p = 1, j = end[i - 1]; j <= end[i]; p = nxt[p][s[j++] - 'a']) if (p != 1) ans += ww[p];
		printf("%lld", ans);
		if (i != n) putchar(' ');
	}
}
