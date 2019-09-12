#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef std::pair<int, int> pa;
const int N = 1e5 + 10, M = 3e5 + 10, K = 4;
const ll INF = 1e15;
int n, m, w[N], top;
pa sk[N];
ll f[K][M], c[K][M];
std::vector<int> pak[4];
ll val(int x, int y, int z) {
	return y >= z ? f[x - 1][z] + c[x][std::min((y - z)/x, (int)pak[x].size())] : -INF;
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int w, c; scanf("%d%d", &w, &c);
		pak[w].push_back(c);
	}
	for (int i = 1; i <= 3; i++) {
		std::sort(pak[i].begin(), pak[i].end(), std::greater<int>());
		for (int j = 0; j < (int)pak[i].size(); j++) c[i][j + 1] = c[i][j] + pak[i][j];
	}
	for (int i = 1; i <= 3; i++) {
		top = 0;
		sk[++top] = pa(0, 0);
		for (int j = 1; j <= m; j++) {
			while (top && val(i, sk[top].first, sk[top].second) <= val(i, sk[top].first, j)) top--;
			int l = sk[top].first, r = m + 1;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (val(i, mid, sk[top].second) <= val(i, mid, j)) r = mid;
				else l = mid + 1;
			}
			if (l <= m) sk[++top] = pa(l, j);
		}
		sk[top + 1] = pa(m + 1, 0);
		for (int k = 1; k <= top; k++) {
			for (int j = sk[k].first; j < sk[k + 1].first; j++) {
				f[i][j] = val(i, j, sk[k].second);
			}
		}
	}
	printf("%I64d\n", f[3][m]);
}
