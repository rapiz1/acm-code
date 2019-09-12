#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <assert.h>
#define file(x) "dynrank." #x
#define lch (o << 1)
#define rch ((o << 1) | 1)
#define mid ((l + r) >> 1)
const int N = 3600010;
int n, m, a[N], tpsz;
int v[N], r[N], ch[N][2], cnt[N], s[N];
struct TP{
	int rt;
	inline void up(int o) {
		s[o] = s[ch[o][0]] + s[ch[o][1]] + cnt[o];
	}
	inline void rot(int& o, int d) {
		int t = ch[o][d];
		ch[o][d] =  ch[t][d^1];
		ch[t][d^1] = o;
		up(o);
		o = t;
		up(o);
	}
	void in(int& o, int x) {
		if (!o) {
			v[o = ++tpsz] = x;
			cnt[o] = 1;
			up(o);
			r[o] = rand();
			return;
		}
		if (x == v[o]) {
			cnt[o]++;
			up(o);
		}
		else {
			int d = x > v[o];
			in(ch[o][d], x);
			up(o);
			if (r[ch[o][d]] > r[o]) rot(o, d);
		}	
	}
	void rm(int o, int x) {
		if (v[o] == x) cnt[o]--;
		else rm(ch[o][x > v[o]], x);
		up(o);
	}
	int count(int o, int x) {
		int r = 0;
		while (o) {
			if (x > v[o]) r += s[ch[o][0]] + cnt[o], o = ch[o][1];
			else if (x == v[o]) return r += s[ch[o][0]] + cnt[o];
			else o = ch[o][0];
		}
		return r;
	}
	void lmr(int o) {
		if (o) {
			lmr(ch[o][0]);
			for (int i = 1; i <= cnt[o]; i++) printf("%d ", v[o]);
			lmr(ch[o][1]);
		}
	}
	inline void show() {
		lmr(rt);	
		puts("");
	}
	bool find(int o, int x) {
		if (!o) return 0;
		if (ch[o][0]) assert(v[ch[o][0]] < v[o]);
		if (ch[o][1]) assert(v[ch[o][1]] > v[o]);
		if (v[o] == x) return 1;
		else {
			return find(ch[o][0],x) || find(ch[o][1], x);
		}
	}
}tp[N];
void build(int o, int l, int r) { 
	for (int i = l; i <= r; i++) tp[o].in(tp[o].rt, a[i]);
//	printf("[%d, %d]: ", l, r);
//	tp[o].show();
	if (l == r) return;
	build(lch, l, mid), build(rch, mid + 1, r);
}
int q1, q2;
void change(int o, int l, int r) {
//	assert(tp[o].find(tp[o].rt, a[q1]));
	tp[o].rm(tp[o].rt, a[q1]);
	tp[o].in(tp[o].rt, q2);
	if (l == r) return;
	if (q1 <= mid) change(lch, l, mid);
	else change(rch, mid + 1, r);
}
int query(int o, int l, int r, int x) {
	if (l > r) return 0;
	if (q1 <= l && r <= q2) return tp[o].count(tp[o].rt, x);
	int s = 0;
	if (q1 <= mid) s += query(lch, l, mid, x);
	if (q2 > mid) s += query(rch, mid + 1, r, x);
	return s;
}
char cmd[2];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	srand(time(NULL));
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		memset(tp, 0, sizeof(tp));
		memset(v, 0, sizeof(v));
		memset(r, 0, sizeof(r));
		memset(ch, 0, sizeof(ch));
		memset(cnt, 0, sizeof(cnt));
		memset(s, 0, sizeof(s));
		tpsz = 0;
		build(1, 1, n);
		while (m--) {
			scanf("%s%d%d", cmd, &q1, &q2);
			if (cmd[0] == 'Q') {
				int l = 0, r = 1e9, k;
				scanf("%d", &k);
				while (l < r) {
					if (query(1, 1, n, mid) < k) l = mid + 1;
					else r = mid;
				}
				printf("%d\n", l);
			}
			else {
				change(1, 1, n);
				a[q1] = q2;
			}
		}
	}
}
