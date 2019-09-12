#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N = 2e5 + 10;
struct Q{int x,y,i;}qu[N], qq[N], mg[N];
int n, m, th[N], a[N], mxv; 
ll ans[N];
inline int lowbit(int x) {return x&-x;}
inline void add(int p, int v) {
	while (p <= mxv) a[p] += v, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += a[p], p -= lowbit(p);
	return s;
}
inline int sum(int l, int r) {return pre(r) - pre(l - 1);}
std::stack<int> rec;
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1, sz = 0;
	while (i <= mid || j <= r) {
		if (i > mid || (j <= r && qq[j].x < qq[i].x)) {
			int f = qq[j].y < 0 ? -1 : 1;
			ans[qq[j].i] += f*sum(f*qq[j].y + 1, mxv);
			mg[sz++] = qq[j++];
		}	
		else {
			int f = qq[i].y < 0 ? -1 : 1;
			add(f*qq[i].y, f);
			rec.push(i);
			mg[sz++] = qq[i++];
		}
	}
	while (!rec.empty()) {
		int x = rec.top(), f = qq[x].y < 0 ? -1 : 1;
		rec.pop();
		add(f*qq[x].y, -f);
	}
	memcpy(qq + l, mg, sizeof(Q)*sz);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &qu[i].y), qu[i].i = i, qu[i].x = i, th[qu[i].y] = i;
	for (int i = n + 1; i <= n + m; i++) scanf("%d", &qu[i].y), qu[i].x = th [qu[i].y], qu[i].i = i, qu[i].y*=-1;
	for (int i = 1; i <= n; i++) mxv = std::max(mxv, qu[i].y);
	memcpy(qq, qu, sizeof(qu));
	solve(1, n + m);
	for (int i = 1; i <= n + m; i++) {
		qq[i] = qu[i];
		qq[i].x = n + 1 - qq[i].x;
		int f = qq[i].y < 0 ? -1 : 1;
		qq[i].y = (mxv + 1 - f*qq[i].y)*f;
	}
	solve(1, n + m);
	for (int i = 1; i <= n + m; i++) ans[i] += ans[i - 1];
	for (int i = n; i < n + m; i++) printf("%lld\n", ans[i]);
}
