#include <cstdio>
#include <cstring>
const int L = 80;
int k, n, m;
char lt[256][4], a[L], b[L];
bool dfs(int p, int q) {
	if (p >= n || q >= m) return p == n && q == m;
	else {
		if (lt[a[p]][0]) {
			bool f = 1;
			int l = strlen(lt[a[p]]);
			for (int i = 0; i < l; i++) if (b[q + i] != lt[a[p]][i]) f = 0;
			if (f) return dfs(p + 1, q + l);
			else return 0;
		}
		else {
			for (int i = 1; i <= k; i++) {
				for (int j = 0; j < i; j++) lt[a[p]][j] = b[q + j];	
				bool f = dfs(p + 1, q + i);
				for (int j = 0 ; j < i; j++) lt[a[p]][j] = 0;
				if (f) return 1;
			}
		}
	}
	return 0;
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	int T;scanf("%d", &T);
	while (T--) {
		scanf("%d%s%s", &k, a, b);
		memset(lt, 0, sizeof(lt));
		n = strlen(a), m = strlen(b);
		printf("%d\n", dfs(0, 0)); 
	}
}
