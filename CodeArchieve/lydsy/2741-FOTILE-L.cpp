#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
const int N = 12010, S = N*35, SQN = 120;
int n, m, rt[S], ch[S][2], ans, a[N], sz, cnt[S], f[SQN][N], bk;
void in(int& o, int p, int x, int dep) {
	if (dep > 31) return;
	o = ++sz;
	memcpy(ch[o], ch[p], sizeof(ch[o]));
	cnt[o] = cnt[p] + 1;
	in(ch[o][x&1], ch[p][x&1], x >> 1, dep + 1);
}
int query(int p, int q, int x, int dep) {
	if (dep > 31) return 0;
	if (cnt[ch[p][(x&1)^1]] - cnt[ch[q][(x&1)^1]] > 0) 
		return (1 << 30 - dep) + query(ch[p][(x&1)^1], ch[q][(x&1)^1], x >> 1, dep + 1);
	else return query(ch[p][x&1], ch[q][x&1], x >> 1, dep + 1);
}
int query(int p, int q, int x) {
	int s = 0;
	for (int i = 0; i < 31; i++) {
		int d = x&1;
		s <<= 1;
		if (cnt[ch[p][d^1]] - cnt[ch[q][d^1]] > 0) p = ch[p][d^1], q = ch[q][d^1], s++;
		else p = ch[p][d], q = ch[q][d];
		x >>= 1;
	}
	return s;
}
inline int rev(int x) {
	int s = 0;
	for (int i = 0; i < 31; i++) if (x >> i & 1) s |= 1 << (30 - i);
	return s;
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	scanf("%d%d", &n, &m);
	bk = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] ^= a[i - 1];
		in(rt[i], rt[i - 1], rev(a[i]), 0);
	}
	for (int i = 1; i <= n; i++) a[i] = rev(a[i]);
	for (int i = 0; i <= n/bk; i++) for (int j = std::max(i*bk, 1); j <= n; j++)
		f[i][j] = std::max(f[i][j - 1], query(rt[j], rt[std::max(i*bk, 1) - 1], a[j]));
	for (int j = 1; j <= n; j++) f[0][j] = std::max(f[0][j], rev(a[j]));
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = (l*1ll + ans)%n + 1;
		r = (r*1ll + ans)%n + 1;
		if (l > r) std::swap(l, r);
		int li = l/bk, rr = std::min((li + 1)*bk, n);
		ans = 0;
		if (rr <= r) {
			for (int i = l - 1; i <= rr; i++) ans = std::max(ans, query(rt[r], rt[l - 1], a[i]));
			ans = std::max(ans, f[li + 1][r]);
		}
		else for (int i = l - 1; i <= r; i++) {
			ans = std::max(ans, query(rt[r], rt[l - 1], a[i]));
		}
		printf("%d\n", ans);
	}
}
