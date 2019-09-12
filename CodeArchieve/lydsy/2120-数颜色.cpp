#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#define file(x) "nt2011_color."#x
const int N = 10010, CO = 1e6 + 10;
struct Q{int l, r, t, i;}st[N];
struct C{int i, x, y, z;}ca[N];
std::stack<C> modi;
int n, m, a[N], ans[N], tot, bk, cnt[CO], nans;
char cmd[2];
bool operator<(const Q& a,const Q& b) {
	if (a.l/bk == b.l/bk) {
		if (a.r/bk == b.r/bk) return a.t < b.t;
		else return a.r/bk < b.r/bk;
	}
	else return a.l/bk < b.l/bk;
}
inline void inc(int pos) {
	nans += cnt[a[pos]]++ == 0;
}
inline void dec(int pos) {
	nans -= --cnt[a[pos]] == 0;
}
inline bool inr(int x, int l, int r) {return l <= x && x <= r;}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	bk = pow(n, 1.0/3);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, j = 0; i <= m; i++) {
		int x, y;
		scanf("%s%d%d", cmd, &x, &y);	
		if (cmd[0] == 'Q') st[i - j] = (Q){x, y, j, i - j}, tot++;
		else ++j, ca[j] = (C){j, x, y};
	}
	std::sort(st + 1, st + 1 + tot);
	int l = 1, r = 1, nt = 0;
	nans = 1;
	cnt[a[1]]++;
	for (int i = 1; i <= n; i++) {
		int ll = st[i].l, rr = st[i].r, tt = st[i].t;
		while (l > ll) inc(--l);
		while (r < rr) inc(++r);
		while (l < ll) dec(l++);
		while (r > rr) dec(r--);
		while (nt < tt) {
			C cc = ca[++nt];			
			if (inr(cc.x, l, r)) dec(cc.x);
			cc.z = a[cc.x];
			modi.push(cc);
			a[cc.x] = cc.y;
			if (inr(cc.x, l, r)) inc(cc.x);
		}
		while (nt > tt) {
			--nt;
			C cc = modi.top();modi.pop();
			if (inr(cc.x, l, r)) dec(cc.x);
			a[cc.x] = cc.z;
			if (inr(cc.x, l, r)) inc(cc.x);
		}
		ans[st[i].i] = nans;
	}
	for (int i = 1; i <= tot; i++) printf("%d\n", ans[i]);
}
