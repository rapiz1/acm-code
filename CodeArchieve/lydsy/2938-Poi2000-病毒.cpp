#include <cstdio>
const int V = 3e4 + 10;
int n, ch[V][2], fail[V], sz, q[V], h, t, vis[V];
bool end[V];
char s[V];
bool dfs(int u) {
	vis[u] = -1;
	for (int i = 0; i < 2; i++) if (!end[ch[u][i]]){
		if (vis[ch[u][i]] < 0) return 0;
		if (vis[ch[u][i]] == 0 && !dfs(ch[u][i])) return 0;
	}
	vis[u] = 1;
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int now = 0;
		for(char* p = s; *p; p++) {
			if (!ch[now][*p - '0']) ch[now][*p - '0'] = ++sz;
			now = ch[now][*p - '0'];
		}
		end[now] = 1;
	}
	for (int i = 0; i < 2; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int x = q[h++];
		if (end[fail[x]]) end[x] = 1;
		for (int i = 0; i < 2; i++) if (ch[x][i]) {
			q[t++] = ch[x][i];
			int p = fail[x];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[x][i]] = ch[p][i];
		}else ch[x][i] = ch[fail[x]][i];
	}
	puts(dfs(0) ? "NIE" : "TAK");
}
