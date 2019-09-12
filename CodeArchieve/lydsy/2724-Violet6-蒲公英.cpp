#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
const int N = 40010, SQN = 210;
int cnt[SQN][N], n, m, a[N], ans[SQN][SQN], th[N], bk, res, cct[N], rev[N];
bool cmp(int i, int j) {return a[i] < a[j];}
int count(int i, int j, int x ){
	return cnt[j][x] - (i - 1 >= 0 ? cnt[i - 1][x] : 0);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	bk = sqrt(n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), th[i] = i;
	std::sort(th + 1, th + 1 + n, cmp);
	for (int i = 1, c = 0; i <= n;) {
		int j = i;
		while (j + 1 <= n && a[th[i]] == a[th[j + 1]]) j++;
		rev[++c] = a[th[i]];
		while (i <= j) a[th[i++]] = c;
	}
	for (int i = 1; i <= n; i++) {
		cnt[i/bk][a[i]]++;
	}
	for (int i = 0; i <= n/bk; i++) {
		for (int j = 1; j <= n; j++) cct[j] = 0;
		int ll = std::max(i*bk, 1);
		for (int j = i; j <= n/bk; j++) {
			if (j >= 1) ans[i][j] = ans[i][j - 1];
			int rr = std::min(j*bk + bk - 1, n);
			while (ll <= rr) {
				cct[a[ll]]++;
				if (cct[a[ll]] > cct[ans[i][j]] || (cct[a[ll]] == cct[ans[i][j]] && a[ll] < ans[i][j]))  ans[i][j] = a[ll];
				ll++;
			}
		}
	}
	for (int i = 1; i <= n/bk; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[i][j] += cnt[i - 1][j];
		} 
	}
	for (int i = 1; i <= n; i++) cct[i] = 0;
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = (1ll*l + res - 1)%n + 1;
		r = (1ll*r + res - 1)%n + 1;
		if (l > r) std::swap(l, r);
		int li = l/bk + 1, ri = r/bk - 1,
				ll = li*bk, rr = std::min(n, ri*bk + bk - 1);
		if (li < ri) {
			res = ans[li][ri];
			for (int i = l; i < ll; i++) {
				cct[a[i]]++;
				int x = cct[a[i]] + count(li, ri, a[i]), y = cct[res] + count(li, ri, res);
				if (x > y || (x == y && a[i] < res))  res = a[i];
			}
			for (int i = rr + 1; i <= r; i++) {
				cct[a[i]]++;
				int x = cct[a[i]] + count(li, ri, a[i]), y = cct[res] + count(li, ri, res);
				if (x > y || (x == y && a[i] < res))  res = a[i];
			}
			for (int i = l; i < ll; i++) cct[a[i]]--;
			for (int i = rr + 1; i <= r; i++) cct[a[i]]--;
		}
		else {
			res = a[l];
			for (int i = l; i <= r; i++) {
				cct[a[i]]++;
				if (cct[a[i]] > cct[res] || (cct[a[i]] == cct[res] && a[i] < res)) res = a[i];
			}
			for (int i = l; i <= r; i++) cct[a[i]]--;
		}
		printf("%d\n", res = rev[res]);
	}
}
