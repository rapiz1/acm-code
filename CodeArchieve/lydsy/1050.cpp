#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
const int V = 510, E = 5010*2;
struct Edge{int u, v, w;
	bool operator<(const Edge& rhs)const {return w < rhs.w;}
}st[E];
int n, m, aa=2e9, ab=1, p[V], s, t, dis;
std::vector<int> to[V];
bool in[E];
bool dfs(int u, int fa, int dis) {
	if (u == t) {
		::dis = dis;
		return 1;
	}
	for (int i  =0 ; i   < (int)to[u].size(); i++) if (in[to[u][i]]){
		int v =  st[to[u][i]].v;
		if (v != fa) {
			if (dfs(v, u, std::max(st[to[u][i]].w, dis))) return 1;
		}
	}
	return 0;
}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int find(int x) {return x == p[x]  ? x : p[x]  = find(p[x]);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &st[i].u, &st[i].v, &st[i].w);
	}
	scanf("%d%d", &s, &t);
	std::sort(st + 1, st + 1 + m);
	for (int i = 1; i <= m; i++) st[i+m] = st[i], std::swap(st[i+m].u, st[i+m].v);
	for (int i = 1; i <= 2*m; i++) {
		to[st[i].u].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) p[j] = j;
		memset(in, 0, sizeof in);
		for (int j = i; j <= m; j++) {
			int x = find(st[j].u), y = find(st[j].v);
			if (x != y) p[x] = y, in[j] = in[j+m] = 1;
		}
		dis=-1;
		dfs(s, 0, 0);
		if (dis >= 0 && (double)dis/st[i].w < (double)aa/ab) aa = dis, ab = st[i].w;
	}
	int d = gcd(aa, ab);
	aa/=d, ab/=d;
	if (aa < 2e9) {
		if (ab > 1) printf("%d/%d\n", aa, ab);
		else printf("%d\n", aa);
	}
	else puts("IMPOSSIBLE");
}
