#include <cstdio>
#include <cstring>
#include <algorithm>
#define file(x) "zjoi13_sequence." #x
const int N = int(5e4 + 10) << 2;
struct Q {
	int x, y, z, t, ans;
}qu[N];
int n, m, t1[N], t2[N], a[N], mxi, mni;
inline int lowbit(int x) {return x&-x;}
namespace BIT {
long long a[N], b[N];
int stk[N], sz;
inline void add(long long* v, int p, int x) {
	stk[++sz] = p;
	while (p <= n) v[p] += x, p += lowbit(p);
}
inline void clear(long long* v, int p) {
	while (p <= n) v[p] = 0, p += lowbit(p);
}
inline void reset() {
	while (sz) {
		clear(a, stk[sz]);
		clear(b, stk[sz]);
		--sz;
	}
}
inline long long pre(long long* v, int p) {
	long long s = 0;
	while (p) s += v[p], p -= lowbit(p);
	return s;
}
inline void modi(int l, int r, int x) {
	add(a, l, x), add(a, r + 1, -x);
	add(b, l, l*x), add(b, r + 1, -(r + 1)*x);
}
inline long long pp(int p) {return pre(a, p)*(p + 1) - pre(b, p);}
inline long long sum(int l, int r) {return pp(r) - pp(l - 1);}
}
void solve(int l, int r, int ll, int rr) {
	if (l > r) return;
	if (ll == rr)  {
		for (int i = l; i <= r; i++) qu[a[i]].ans = ll;
		return;
	}
	int mid = 1ll*ll + rr + 1 >> 1, c1 = 0, c2 = 0;
	for (int k = l; k <= r; k++) 	{
		int i = a[k];
		if (qu[i].t == 1) {
			if (qu[i].z >= mid) BIT::modi(qu[i].x, qu[i].y, 1), t2[c2++] = i;
			else t1[c1++] = i;
		}
		else {
			long long tmp;
			if ((tmp = BIT::sum(qu[i].x, qu[i].y)) < qu[i].z) t1[c1++] = i, qu[i].z -= tmp;
			else t2[c2++] = i;
		}
	}
	memcpy(a + l, t1, sizeof(int)*c1);
	memcpy(a + l + c1, t2, sizeof(int)*c2);
	BIT::reset();
	solve(l, l + c1 - 1, ll, mid - 1), solve(l + c1, r, mid, rr);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &qu[i].t, &qu[i].x, &qu[i].y, &qu[i].z);
		if (qu[i].t == 1) mni = std::min(qu[i].z, mni), mxi = std::max(qu[i].z, mxi);
		a[i] = i;
	}
	solve(1, m, mni, mxi);
	for (int i = 1; i <= m; i++) if (qu[i].t == 2) printf("%d\n", qu[i].ans);
}
