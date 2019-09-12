#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#define lch (o << 1)
#define rch ((o<<1)|1)
#define mid ((l + r)>>1)
const int V = 200010, M = 100010;
typedef std::pair<int, int> pa;
int n, m, p[V], ans[M], rk[V];
std::vector<pa> op[M << 2];
std::map<pa, int> st;
inline int zip(int x, int y) {return (x - 1)*n + y;}
int find(int x) {return x == p[x] ? x : find(p[x]);}
char cmd[100];
pa now;
void ins(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) op[o].push_back(now);
	else {
		if (q1 <= mid) ins(lch, l, mid, q1, q2);
		if (mid < q2) ins(rch, mid + 1, r, q1, q2);
	}
}
struct Tri {int x, y, z;};
void dfs(int o, int l, int r) {
	std::vector<Tri> rec;
	for (int i = 0; i < (int)op[o].size(); i++) {
		now = op[o][i];
		if (now.second < 0) continue;
		int x = find(now.first), y = find(now.second);
		int f = 0;
		if (rk[x] > rk[y]) std::swap(x, y);
		else if (rk[x] == rk[y]) rk[y]++, f = 1;
		rec.push_back((Tri){x, y, rk[y] - f});
		p[x] = y;
	}
	if (l == r) {
		for (int i = 0; i < (int)op[o].size(); i++) {
			now = op[o][i];
			if (now.second > 0) continue;
			now.second *= -1;
			ans[l] = (find(now.first) == find(now.second));
		}
	}
	else dfs(lch, l, mid), dfs(rch, mid + 1, r);
	for (int i = rec.size() - 1; ~i; i--) {
		Tri x = rec[i];
		p[x.x] = x.x, rk[x.y] = x.z;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2*n; i++) p[i] = i;
	while (scanf("%s", cmd) != EOF) {
		if (cmd[0] == 'E') break;
		m++;
		int r1, c1, r2, c2;scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int x = zip(r1, c1), y = zip(r2, c2);
		if (x > y) std::swap(x, y);
		now = std::make_pair(x, y);
		if (cmd[0] == 'O') {
			if (!st[now]) st[now] = m;
		}
		else if (cmd[0] == 'C') {
			if (st[now]) ins(1, 1, 1e5, st[now], m);
			st[now] = 0;
		}
		else {
			now.second *= -1;
			ins(1, 1, 1e5, m, m); 
		}
	}
	for (std::map<pa, int>::iterator it = st.begin(); it != st.end(); it++) if (it->second) now = it->first, ins(1, 1, 1e5, it->second, m);
	for (int i = 1; i <= m; i++) ans[i] = -1;
	dfs(1, 1, 1e5);
	for (int i = 1; i <= m; i++) if (ans[i] != -1) puts(ans[i] ? "Y" : "N");
}
