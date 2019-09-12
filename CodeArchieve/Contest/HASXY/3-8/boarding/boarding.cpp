#include <cstdio>
#include <cstring>
#include <algorithm>
#define file(x) "boarding." #x
typedef long long ll;
const int N = 2e5 + 10;
int n;
ll ans[N];
struct ST{int s, i;ll t;
	bool operator<(const ST& b) {return s < b.s;}
}st[N], tmp[N];
void solve(int l, int r) {
	if (l == r) {
		ans[st[l].i] = std::max(ans[st[l].i], st[l].t);
		return;
	}
	int mid = l + r >> 1;
	for (int i = l, p = l, q = mid + 1; i <= r; i++) 
		if (st[i].i <= mid) tmp[p++] = st[i];
		else tmp[q++] = st[i];
	for (int i = l; i <= r; i++) st[i] = tmp[i];
	solve(l, mid);
	ll tt = 0;
	for (int i = l, j = mid + 1; j <= r; j++) {
		while (st[i]. s < st[j].s) tt = std::max(ans[st[i].i], tt), i++;
		ans[st[j].i] = std::max(ans[st[j].i], tt + st[j].t);
	}
	solve(mid + 1, r);
}
int main() {
	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = n; i >=1; i--) scanf("%d%lld", &st[i].s, &st[i].t), st[i].i = i;
	std::sort(st + 1, st + 1 + n);
	solve(1, n);
	printf("%lld\n", ans[n]);
}
