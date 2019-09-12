#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
const int N = 1e6 + 10;
int n, sz = 1, last = 1, pre[N], nxt[N][26], val[N], ri[N], qu[N], cc[N], rmx[N];
char s[N];
bool vis[N];
long long ans;
inline void extend(int c) {
	int p = last, np = last = ++sz;
	val[np] = val[p] + 1;
	ri[np]++;
	for(;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1;
			pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			pre[np] = pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
}
int main(){
//	freopen("input", "r", stdin);
	freopen("apio2014_palindrome.in", "r", stdin);
	freopen("apio2014_palindrome.out", "w", stdout);
	scanf("%s", s + 1);
	for (int i = 1; s[i]; i++) rmx[sz + 1] = i, extend(s[i] - 'a'), n++;
	for (int i = 1; i <= sz; i++) cc[val[i]]++;
	for (int i = 1; i <= sz; i++) cc[i] += cc[i - 1];
	for (int i = sz; i; i--) qu[cc[val[i]]--] = i;
	for (int i = sz; i; i--) {
		int t = qu[i];
		ri[pre[t]] += ri[t]; 
		rmx[pre[t]] = std::max(rmx[pre[t]], rmx[t]);
	}
	for (int i = n, p = 1, len = 0; i; i--) {
		int c = s[i] - 'a';
		for (;p&&!nxt[p][c]; p = pre[p]);
		if (nxt[p][c]) len = std::min(len + 1, val[p] + 1), p = nxt[p][c];
		else len = 0, p = 1;
		if (rmx[p] < i + len) {
			if (i <= rmx[p]) ans = std::max((rmx[p] - i + 1ll)*ri[p], ans);
			for (int x = pre[p]; x && !vis[x]; x = pre[x]) {
				vis[x] = 1;
			 	if (rmx[x] < i + val[x] && i <= rmx[x])
				ans = std::max((rmx[x] - i + 1ll)*ri[x], ans);
			}
		}
	}
	printf("%lld\n", ans);
}
