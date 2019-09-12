#include <cstdio>
#include <vector>
#include <cstring>
const int C = 26, N = 4010;
typedef long long ll;
struct Edge{int v, w;};
int ch[N][C], sz, n, q, cnt[N], pos[N];
std::vector<Edge> to[N];
ll ans[N][N], tmp[N];
void dfs(int u, int fa) {
	cnt[pos[u]]++;
	for (int i = 0; i< (int)to[u].size(); i++) {
		int v = to[u][i].v, w = to[u][i].w;
		if (v == fa) continue;
		if (!ch[pos[u]][w]) ch[pos[u]][w] = ++sz;
		pos[v] = ch[pos[u]][w];
		dfs(v, u);
	}
}
void calc(int u) {
	ll pp = tmp[u] + cnt[u];
	for (int i = 0; i < C; i++) if (ch[u][i]) {
		tmp[ch[u][i]] = pp;
		calc(ch[u][i]);
		pp += cnt[ch[u][i]];
		cnt[u] += cnt[ch[u][i]];
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		char buf[2];
		int u, v;
		scanf("%d%d%s", &u, &v, buf);
		Edge x = (Edge){v, (int)buf[0] - 'a'};
		to[u].push_back(x);
		x.v = u;
	 	to[v].push_back(x);
	}
	for (int i =1;  i <= n; i++) {
		memset(ch, 0, sizeof ch);
		memset(tmp, 0, sizeof tmp);
		memset(cnt, 0, sizeof cnt);
		sz=0;
		pos[i] = 0;
		dfs(i, 0);
		cnt[0] = 0;
//		for (int i = sz; ~i; i--) for (int j = 0; j < C; j++) if (ch[i][j]) cnt[i] += cnt[ch[i][j]];
		calc(0);
		for (int j = 1; j <= n; j++) ans[i][j] = tmp[pos[j]];
	}
	while (q--) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%lld\n", ans[u][v]);
	}
}
