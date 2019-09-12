#include <cstdio>
#include <algorithm>
#include <cmath>
using std::max;
using std::min;
const int N  = 5e4 + 10, SQN = 230;
typedef long long ll;
int n, m, bk, a[N], ww, ans;
ll b[SQN][N];
namespace BIT{
	int a[N];
	inline int lowbit(int x) {return x&-x;}
	void add(int p, int v) {
		for (;p <= ww; p += lowbit(p)) a[p] += v;
	}
	ll pre(int x) {
		ll ret = 0;
		for (;x;x -= lowbit(x)) ret += a[x];
		return ret;
	}
	ll sum(int l, int r) {return pre(r) - pre(l - 1);}
}
bool cmp(int i, int j) {return a[i] < a[j];}
int less(int l, int r, int x) {return b[r][x - 1] - b[l - 1][x - 1];}
int greater(int l, int r, int x) {return b[r][ww] - b[l - 1][ww] - less(l, r, x + 1);}
int main() {
	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	bk = sqrt(n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	{// lisan
		static int th[N];
		for (int i = 1; i <= n; i++) th[i] = i;
		std::sort(th + 1, th + 1 + n, cmp);
		for (int i = 1, j; i <= n; i = j) {
			for (j = i; a[th[j + 1]] == a[th[i]]; j++);
			++ww;
			for (int k = i; k <= j; k++) a[th[k]] = ww;
		}
	}
	for (int i = 1; i <= n; i++) b[i/bk][a[i]]++;
	for (int i = 0; i <= n/bk; i++) {
		if (i) for (int j = 0; j <= ww; j++) b[i][j] += b[i - 1][j];
		for (int j = 1; j <= ww; j++) b[i][j] += b[i][j - 1];
	}
	while (m--) {
		int l, r;scanf("%d%d", &l, &r);
		l ^= ans, r ^= ans;
		ans = 0;
		int li = l/bk, ri = r/bk, ll = li*bk + bk - 1, rr = ri*bk;
		if (li + 1 <= ri - 1) {
			for (int i = l; i <= ll; i++) ans += less(li + 1, ri - 1, a[i]);
			for (int i = rr; i <= r; i++) ans += greater(li + 1, ri - 1, a[i]);
		}
		for (int i = l; i <= ll; i++) {
			BIT::add(a[i], 1);
			ans += BIT::sum(a[i] + 1, ww);
		}
		for (int i = rr; i <= r; i++) {
			BIT::add(a[i], 1);
			ans += BIT::sum(a[i] + 1, ww);
		}
		printf("%d\n", ans);
	}
}
