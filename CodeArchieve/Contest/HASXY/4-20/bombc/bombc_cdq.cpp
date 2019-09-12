#include <cstdio>
#include <algorithm>
#define mid ((l + r)>>1)
const int N = 2e5 + 10;
struct Cmd {
	int t, id, x, y, d;
}op[N], tmp[N];
int n, m, mxx, top, s[N], ch[N][2], rt, ans[N];
bool cl[N];
inline void mkcl(int o) {if (o) s[o] = 0,cl[o] = 1;}
inline void down(int o) {
	if (cl[o]) mkcl(ch[o][0]), mkcl(ch[o][1]), cl[o] = 0;
}
void add(int& o, int l, int r, int q1) {
	if (!o) o = ++top;
	if (l == r) s[o]++;
	else {
		down(o);
		if (q1 <= mid) add(ch[o][0], l, mid, q1);
		else add(ch[o][1], mid + 1, r, q1);
		s[o] = s[ch[o][0]] + s[ch[o][1]];
	}
}
void clean(int& o, int l, int r, int q1, int q2) {
	if (!o) return;
	if (q1 <= l && r <= q2) mkcl(o);
	down(o);
	if (q1 <= mid) clean(ch[o][0], l, mid, q1, q2);
	if (mid < q2) clean(ch[o][1], mid + 1, r, q1, q2);
	s[o] = s[ch[o][0]] + s[ch[o][1]];
}
int query(int& o, int l, int r, int q1, int q2) {
	if (!o) return 0;
	if (q1 <= l && r <= q2) return s[o];
	down(o);
	int x = 0;
	if (q1 <= mid) x += query(ch[o][0], l, mid, q1, q2);
	if (mid < q2) x += query(ch[o][1], mid + 1, r, q1, q2);
	return x;
}
void solve(int l, int r) {
	if (l == r) return;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1;
	while (i <= mid || j <= r) {
		if (i > mid || (j <= r && op[j].d < op[i].d)) {
			if (op[j].t == 1) ans[op[j].id] += query(rt, 0, mxx, op[j].x, op[j].y);
			tmp[j] = op[j];
			j++;
		}
		else {
			if (op[i].t == 0) add(rt, 0, mxx, op[i].x);
			else clean(rt, 0, mxx, op[i].x, op[i].y);
			tmp[i] = op[i];
			i++;
		}
	}
	for (int k = l; k <= r; k++) op[k] = tmp[k];
	for (;top;top--) {
		s[top] = ch[top][0] = ch[top][1] = cl[top] = 0;
	}
	rt = 0;
}
void work() {
	mxx = 0;
	for (int i = 1; i <= n + 2*m; i++) op[i] = {0};
	for (int i = 1; i <= n; i++) scanf("%d%d", &op[i].x, &op[i].d), op[i].t = 0, mxx = std::max(op[i].x, mxx);
	scanf("%d", &m);
	for (int i = 1, r, x; i <= m; i++) scanf("%d%d%d", &op[n + i].d, &r, &x), op[n + i].x = std::max(x - r, 0), op[n + i].y = std::min(x + r, mxx), op[n + i].id = i, ans[i] = 0, op[n + i].t = 1;
	solve(1, n + m);
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
int main() {
	freopen("bombc.in", "r", stdin);
	while (scanf("%d", &n), n) work();
}
