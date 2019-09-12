#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
const int N = 2e5 + 10, LG = 20, V = N*LG;
int n, k, top, s[V], ch[V][2], rt[N], la, pre[N];
std::queue<int> q[N];
void add(int& o, int p, int l, int r, int x, int y) {
	o = ++top;
	memcpy(ch[o], ch[p], sizeof ch[0]);
	s[o] = s[p] + y;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) add(ch[o][0], ch[p][0], l, mid, x, y);
	else add(ch[o][1], ch[p][1], mid + 1, r, x, y);
}
int query(int o, int p, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return s[o] - s[p];
	int mid = (l + r) >> 1, ret = 0;
	if (ll <= mid) ret += query(ch[o][0], ch[p][0], l, mid, ll, rr);
	if (mid < rr) ret += query(ch[o][1], ch[p][1], mid + 1, r, ll, rr);
	return ret;
}
int main(){ 
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		int tmp;
	 	add(tmp, rt[i - 1], 1, n, i, 1);
		q[x].push(i);
		if ((int)q[x].size() > k) {
			int xx = q[x].front(); q[x].pop();
			add(rt[i], tmp, 1, n, xx, -1);
		}
		else rt[i] = tmp;
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r);
		l = (l + la)%n + 1, r = (r + la)%n + 1;
		if (l > r) std::swap(l, r);
		printf("%d\n", la = query(rt[r], rt[l - 1], 1, n, l, r));
	}
}
