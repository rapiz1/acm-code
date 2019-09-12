#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
const int N = 1e5 + 10, K = 2e5 + 10;
struct P{int s, x, y, a, w;
	bool operator<(const P& b)const{
		if (s != b.s) return s < b.s;
		else if (x != b.x) return x < b.x;
		else return y < b.y;
	}
	bool operator==(const P& b)const {return s == b.s && x == b.x && y == b.y;}
}qu[N], mg[N];
int n, k, ans[N], a[K];
inline int lowbit(int x){return x&-x;}
inline void add(int p, int v) {
	while (p <= k) a[p] += v, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += a[p], p -= lowbit(p);
	return s;
}
std::stack<int> rec;
void solve(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1, sz = 0;
	while (i <= mid || j <= r) { if (i > mid || (j <= r && qu[j].x < qu[i].x)) {
			qu[j].a += pre(qu[j].y);
			mg[sz++] = qu[j++];
		}
		else {
			add(qu[i].y, qu[i].w);
			rec.push(i);
			mg[sz++] = qu[i++];
		}
	}
	while (!rec.empty()) {
		int x = rec.top();
		rec.pop();
		add(qu[x].y, -qu[x].w);
	}
	memcpy(qu + l, mg, sizeof(P)*sz);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &qu[i].s, &qu[i].x, &qu[i].y);
	}
	std::sort(qu + 1, qu + 1 + n);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j + 1 <= n && qu[j + 1] == qu[i]) j++;
		mg[++tot] = qu[i];
		mg[tot].w = j - i + 1;
		i = j;
	}
	memcpy(qu, mg, sizeof(mg));
	solve(1, tot);
	for (int i = 1; i <= n; i++) ans[qu[i].a + qu[i].w - 1] += qu[i].w;
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
}
