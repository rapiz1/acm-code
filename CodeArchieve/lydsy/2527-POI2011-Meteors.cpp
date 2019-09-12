#include <cstdio>
#include <cctype>
#include <cstring>
namespace I {
	const int L = 1 << 15;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return  *s++;
	} 
	inline int gi() {
		int x = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x = x*10 + ch - '0', ch = gc();
		return x;
	}
}using I::gi;
typedef long long ll;
const int N = 3e5 + 10;
int n, m, k, t[N], ans[N], dd[N], d1[N], d2[N], hed[N], nxt[N], cur[N];
ll v[N];
inline int lowbit(int x) {return x&-x;}
inline void add(int p, int x) {
	while (p <= m + 1) v[p] += x, p += lowbit(p);
}
inline ll pre(int p) {
	ll s = 0;
	while (p) s += v[p], p -= lowbit(p);
	return s;
}
struct R{int l, r, w;
	void ap(int f = 0)const {
		f = f ? -1: 1;
		if (l <= r) add(l, w*f), add(r + 1, -w*f);
		else add(l, w*f), add(m + 1, -w*f), add(1, w*f), add(r + 1, -w*f);
	}
}me[N];
void solve(int l, int r, int al, int ar) {
	if (l > r) return;
	if (al == ar) {
		while (l <= r) ans[dd[l++]] =  al;
		return;
	}
	int am = al + ar >> 1;
	for (int i = al; i <= am; i++) me[i].ap();
	int p = 0, q = 0;
	for (int i = l; i <= r; i++) {
		int k = dd[i];
		ll c = 0;
		for (int j = hed[k]; j; j = nxt[j]) {
			c += pre(j);
			if (c > t[k] + 10) break;
		}
		if (cur[k] + c < t[k]) cur[k] += c, d1[p++] = k; 
		else d2[q++] = k;
	}
	memcpy(dd + l, d1, p*sizeof(int));
	memcpy(dd + l + p, d2, q*sizeof(int));
	for (int i = al; i <= am; i++) me[i].ap(1);
	solve(l, l + p - 1, am + 1, ar);
	solve(l + p, r, al, am);
}
int main() {
	n = gi(), m = gi();
	for (int i = 1; i <= m; i++) {
		int x = gi();
		nxt[i] = hed[x], hed[x] = i;
	}
	for (int i = 1; i <= n; i++) t[i] = gi(), dd[i] = i;
	k = gi();
	for (int i = 1; i <= k; i++) me[i].l = gi(), me[i].r = gi(), me[i].w = gi();
	me[0].l = 1, me[0].r = m;
	me[k + 1].l = 1, me[k + 1].r = m, me[k + 1].w = 2e9;
	solve(1, n, 0, k + 1);
	for (int i = 1; i <= n; i++) if (ans[i] == k + 1) puts("NIE");
	else printf("%d\n", ans[i]);
}
