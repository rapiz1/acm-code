#include <cstdio>
#include <algorithm>
#define lch (o<<1)
#define rch ((o<<1)|1)
#define mid ((l+r)>>1)
const int N = 2e5 + 10, V = N << 2;
typedef long long ll;
using std::max;
int n, m, k, d;
struct Node {
	ll s[4];// 0,1 left/right; 2 max; 3 sum
}st[V];
Node operator+(const Node& a, const Node& b) {
	Node ret;
	ret.s[0] = max(a.s[0], a.s[3] + b.s[0]);
	ret.s[1] = max(b.s[1], b.s[3] + a.s[1]);
	ret.s[2] = max(max(ret.s[0], ret.s[1]), max(a.s[2], b.s[2]));
	ret.s[2] = max(ret.s[2], a.s[1] + b.s[0]);
	ret.s[3] = a.s[3] + b.s[3];
	return ret;
}
void add(int o, int l, int r, int x, int y) { 
	if (l == r) for (int i = 0; i < 4; i++) st[o].s[i] += y;
	else {
		if (x <= mid) add(lch, l, mid, x, y);
		else add(rch, mid + 1, r, x, y);
		st[o] = st[lch] + st[rch];
	}
}
void build(int o, int l, int r) {
	if (l == r) for (int i = 0; i < 4; i++) st[o].s[i] = -k;
	else {
		build(lch, l, mid); build(rch, mid + 1, r);
		st[o] = st[lch] + st[rch];
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &k, &d);
	build(1, 1, n);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(1, 1, n, x, y);
		puts(st[1].s[2] <= (ll)d*k ? "TAK" : "NIE");
	}
}
