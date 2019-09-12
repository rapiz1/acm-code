#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 100010;
int n, k, h[N], c[N], th[N];
/*
bool cmp(int i, int j) {return h[i] > h[j];}
int see[N][2], sk[N], sz;
*/
std::vector<int> lv[N];
bool cmp(int i, int j) {return h[i] < h[j];}
bool dfs(int p, int u) {
	if (p > n) return 1;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", h + i, c + i);
	/*
	for (int i = 1; i <= n; i++) {
		see[i][0] = sk[std::lower_bound(sk + 1, sk + 1 + sz, i) - (sk + 1)];
		while (sz && h[sk[sz]] < h[i]) sz--;
		sk[++sz] = i;
	}
	sz = 0;
	for (int i = n; i; i--) {
		see[i][1] = sk[std::lower_bound(sk + 1, sk + 1 + sz, i) - (sk + 1)];
		while (sz && h[sk[sz]] < h[i]) sz--;
		sk[++sz] = i;
	}
	*/
}
