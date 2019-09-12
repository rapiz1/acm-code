#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N = int(1e5 + 10) << 1, NL = N*25;
struct O{
	int t, p;
	bool operator<(const O& b)const {return t < b.t;}
}oo[N];
int n, m, s[NL], sz, ch[NL][2], rt[N], tt[N], mxp;
ll ws[NL], ans = 1;
int q1, q2;
inline void up(int o) {
	s[o] = s[ch[o][0]] + s[ch[o][1]];
	ws[o] = ws[ch[o][0]] + ws[ch[o][1]];
}
void change(int& o, int p, int l, int r) {
	o = ++sz;
	if (l == r) {
		s[o] = s[p] + q2;	
		ws[o] = ll(s[o])*l;
		return;
	}
	memcpy(ch[o], ch[p], sizeof(ch[p]));
	int mid = (l + r) >> 1;
	if (q1 <= mid) change(ch[o][0], ch[p][0], l, mid);
	else change(ch[o][1], ch[p][1], mid + 1, r);
	up(o);
}
ll query(int o, int k, int l, int r) {
	if (l == r) return ll(std::min(k, s[o]))*l;
	int mid = (l + r) >> 1;
	if (k <= s[ch[o][0]]) return query(ch[o][0], k, l, mid);
	else return ws[ch[o][0]] + query(ch[o][1], k - s[ch[o][0]], mid + 1, r);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int s, e, p, x = 2*i - 1;
		scanf("%d%d%d", &s, &e, &p);
		oo[x].t = s, oo[x].p = p;
		++x;
		oo[x].t = e + 1, oo[x].p = -p;
		mxp = std::max(mxp, p);
	}
	std::sort(oo + 1, oo + 1 + 2*n);
	for (int i = 1; i <= 2*n; i++) {
		q1 = oo[i].p;
		q2 = q1 > 0 ? 1 : -1;
		q1 = q1 > 0 ? q1 : -q1;
		change(rt[i], rt[i - 1], 1, mxp);	
		tt[oo[i].t] = rt[i];
	}
	for (int i = 1; i <= m; i++) if (!tt[i]) tt[i] = tt[i - 1];
	while (m--) {
		int x, a, b, c;
		scanf("%d%d%d%d", &x, &a, &b, &c);
		int k = 1 + (a*ans + b)%c;
		printf("%lld\n", ans = query(tt[x], k, 1, mxp));
	}
}
