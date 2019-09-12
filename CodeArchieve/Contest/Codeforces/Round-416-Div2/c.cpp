#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 5e3 + 10;
int n, a[N], tot, ans, mx[N], mn[N], cc, p[N];
bool hv[N];
std::vector<int> ion[N];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int main() {
	freopen("input", "r", stdin);
	memset(mn, 0x3f, sizeof mn);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", a + i), cc = std::max(cc, a[i]), mx[a[i]] = std::max(mx[a[i]], i),
			mn[a[i]] = std::min(mn[a[i]], i), hv[a[i]] = 1;
	for (int i = 1; i <= cc; i++) p[i] = i;
	for (int i = 1; i <= cc; i++)
		for (int j = mn[i]; j <= mx[i]; j++) {
			int x = find(i), y = find(a[j]);
			p[x] = y;
		}
	for (int i = 1; i <= cc; i++) if (hv[i]) ion[find(i)].push_back(i);
	for (int i = 1; i <= cc; i++) {
		std::sort(ion[i].begin(), ion[i].end());
		int x = 0, s = std::unique(ion[i].begin(), ion[i].end()) - ion[i].begin();
		for (int j = 0; j < s; j++) x ^= ion[i][j];
		ans += x;
	}
	printf("%d\n", ans);
}
