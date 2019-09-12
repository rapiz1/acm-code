#include <bits/stdc++.h>
//#define DBG
using namespace std;
typedef long long ll;
const int N = 100, L = 1e5 + 10;
int q, dep, len, sz;
ll p2[64], n;
struct ND{ll o, l, r, dep;
	void pt() {
#ifdef DBG
		printf("%lld [%lld, %lld]\n", o, l, r);
#endif
	}
}sk[N];
char s[L];
void gpos(ll o, ll l, ll r, ll dep, ll tar) {
	sk[++sz] = (ND){o, l, r, dep};
	if (tar == o) return;
	else if (tar < o) gpos(o - (p2[dep - 1]) + p2[dep - 2], l, o - 1, dep - 1, tar);
	else gpos(o + p2[dep - 2], o + 1, r, dep - 1, tar);
}
void go(ll o, ll l, ll r, ll dep, int step) {
	sk[sz].pt();
RE:
	if (step > len) {
		printf("%lld\n", o);
		return;
	}
	if (s[step] == 'U') {
		if (dep + 1 <= ::dep) --sz, go(sk[sz].o, sk[sz].l, sk[sz].r, sk[sz].dep, step + 1);
		else {
			step++;
			goto RE;
		}
	}
	else if (s[step] == 'L') {
		if (dep - 1 > 0) sk[++sz] = (ND){o - (p2[dep - 1]) + p2[dep - 2], l, o - 1, dep - 1},
										go(o - (p2[dep - 1]) + p2[dep - 2], l, o - 1, dep - 1, step + 1);
		else {
			step++;
			goto RE;
		}
	}
	else if (s[step] == 'R') {
		if (dep - 1 > 0) sk[++sz] = (ND){o + p2[dep - 2], o + 1, r, dep - 1},
										go(o + p2[dep - 2], o + 1, r, dep - 1, step + 1);
		else {
			step++;
			goto RE;
		}
	}
}
int main() {
	//freopen("input", "r", stdin);
	cin >> n >> q;
	p2[0] = 1;
	for (int i = 1; i <= 62; i++) p2[i] = p2[i - 1]*2;
	dep = log2(n + 1);
	while (q--) {
		sz = 0;
		long long p;
		cin >> p >> (s + 1);
		len = strlen(s + 1);
		gpos(p2[dep - 1], 1, n, dep, p);
#ifdef DBG
		for (int i = 1; i <= sz; i++) printf("%lld [%lld,%lld]\n", sk[i].o, sk[i].l, sk[i].r);
		puts("");
#endif
		go(sk[sz].o, sk[sz].l, sk[sz].r, sk[sz].dep, 1);
	}
}
