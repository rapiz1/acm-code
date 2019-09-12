#include <cstdio>
#include <vector>
const int N = 150010;
int n, m, p[N], cnt[N];
std::vector<int> to[N];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n ;i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y;scanf("%d%d", &x, &y);
		to[x].push_back(y);
		to[y].push_back(x);
		p[find(x)] = find(y);
	}
	for (int i = 1; i <= n; i++) cnt[find(i)]++;
	for (int i = 1; i <= n; i++) {
		int cc = 1;
		for (int j = 0; j < to[i].size(); j++) {
			int v = to[i][j];
			if (find(v) == find(i)) cc++;
		}
		if (cc != cnt[find(i)]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
