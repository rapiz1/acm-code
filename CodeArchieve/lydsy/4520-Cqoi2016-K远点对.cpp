#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
typedef long long ll;
using std::max;
using std::min;
const int N = 1e5 + 10;
int n, k, rt;
struct CMP{
	bool operator()(ll x, ll y) {return x > y;}
};
std::priority_queue<ll, std::vector<ll>, CMP> q;
struct ND{
	int d[2], mn[2], mx[2], ch[2];
}a[N];
inline ll sq(ll x) {return x*x;}
inline ll dis(int x, int y) {
	return sq(a[x].d[0] - a[y].d[0]) + sq(a[x].d[1] - a[y].d[1]);
}
void up(int o) {
	for (int i = 0; i < 2; i++) a[o].mx[i] = a[o].mn[i] = a[o].d[i];
	for (int i = 0; i < 2; i++) if (a[o].ch[i])
		for (int j = 0; j < 2; j++)
			a[o].mx[j] = max(a[o].mx[j], a[a[o].ch[i]].mx[j]),
			a[o].mn[j] = min(a[o].mn[j], a[a[o].ch[i]].mn[j]);
}
void in(int& o, int p, int d) {
	if (!o) o = p;
	else in(a[o].ch[a[p].d[d] > a[o].d[d]], p, d^1);
	up(o);
}
ll val(int o, int p) {
	ll s = 0;
	for (int i = 0; i < 2; i++) s += max(sq(a[o].mn[i] - a[p].d[i]), sq(a[p].d[i] - a[o].mx[i]));
	return s;
}
void query(int o, int p) {
	if (!o) return;
	ll x = dis(o, p);
	if ((int)q.size() == k) {
		if (q.top() < x) q.pop(), q.push(x);
	}
	else q.push(x);
	ll gd[2] = {val(a[o].ch[0], p), val(a[o].ch[1], p)};
	int t = gd[1] < gd[0];
	if ((int)q.size() < k || q.top() < gd[t]) query(a[o].ch[t], p);
	t ^= 1;
	if ((int)q.size() < k || q.top() < gd[t]) query(a[o].ch[t], p);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].d[0], &a[i].d[1]), up(i);
	for (int now = 1; now <= n; now++) {
		query(rt, now);
		in(rt, now, 0);
	}
	printf("%lld\n", q.top());
}
