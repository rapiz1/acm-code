#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 20, K = 1 << N;
int n, f[K], d[N][N], mn[K][N], id[K];
int lowbit(int x) {return x&-x;}
void show(int x) {
	for (int i = 0; i < n; i++) printf("%d", x>>i&1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) id[1 << i] = i;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &d[i][j]);
	memset(f, 0x3f, sizeof f);
	memset(mn, 0x3f, sizeof mn);
	for (int i = 0; i < n; i++) {
		for (int s = 1; s < 1 << n; s++) {
			mn[s][i] = std::min(mn[s - lowbit(s)][i], d[id[lowbit(s)]][i]);
		}
	}
	f[1] = 0;
	for (int s = 2; s < 1 << n; s++) {
		/*
		for (int p = s; p; p -= lowbit(p))
			f[s] = std::min(f[s], f[s - lowbit(p)] + mn[s - lowbit(p)][id[lowbit(p)]]);
			*/
		for (int i = 0; i < n; i++) if (s>>i&1) {
			int ss = s^(1 << i);
			f[s] = std::min(f[s], f[ss] + mn[ss][i]);
		}
	}
	printf("%d\n", f[(1 << n) - 1] + mn[(1 << n) - 1 - 1][0]);
}
