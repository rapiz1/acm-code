#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2e5 + 10, NL = N*19;
int n, m, sz, fa[NL], ch[NL][2], s[NL], rt[N];
void build(int& o, int l, int r) {
	o = ++sz;
	if (l == r) {
		fa[o] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(ch[o][0], l, mid);
	build(ch[o][1], mid + 1, r);
}
int get(int o, int l, int r, int x) {
	if (l == r) return o;
	int mid = l + r >> 1;
	if (x <= mid) return get(ch[o][0], l, mid, x);
	else return get(ch[o][1], mid + 1, r, x);
}
int find(int x, int o) {
	int i = x;
	do {
		x = i;
		i = fa[get(o, 1, n, x)];
	}while (i != x);
	return x;
}
int q1, q2;
void change(int& o, int p, int l, int r) {
	o = ++sz;
	if (l == r) {
		fa[o] = q2;
		return;
	}
	memcpy(ch[o], ch[p], sizeof(ch[p]));
	s[o] = s[p];
	int mid = (l + r) >> 1;
	if (q1 <= mid) change(ch[o][0], ch[p][0], l, mid);
	else change(ch[o][1], ch[p][1], mid + 1, r);
}
int main() {
	scanf("%d%d", &n, &m);
	build(rt[0], 1, n);
	int now = rt[0];
	for (int i = 1; i <= m; i++) {
		int t, x, y;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			scanf("%d", &y);
			x = find(x, now), y = find(y, now);
			int px, py;
			if (s[px = get(now, 1, n, x)] < s[py = get(now, 1, n, y)]) std::swap(x, y);
			else if (s[px] == s[py]) s[px]++;
			q1 = y, q2 = x;
			change(rt[i], now, 1, n); 
			now = rt[i];
		}
		else if (t == 2) {
			now = rt[x];
		}
		else {
			scanf("%d", &y);
			printf("%d\n", find(x, now) == find(y, now));
		}
		rt[i] = now;
	}
}
