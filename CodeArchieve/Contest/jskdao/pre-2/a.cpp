#include <cstdio>
#include <cstring>
const int N = 4, M = 50;
int a[N], tak[N], k, d;
int win(int x, int y) {
	memset(tak, 0, sizeof tak);
//	tak[k] = 2;
	int c = (x+y - 1 + N)%N;
	x = x < y ? x : y;
	int pp = c;
	for (; pp < N; pp = (pp - 1 + N)%N)
		if (x < a[pp]) break;
		else x -= a[pp];
	for (int r = 1; r <= 3; r++)
	for (int i = 0; i < 8; i++) {
		if (k == pp)
			if (x == d || x == d + 1) tak[i/2]++;
		x++;
		for (; pp < N; pp = (pp - 1 + N)%N)
		 	if (x < a[pp]) break;
			else x-= a[pp];
	}
	for (int i = 0; i < N; i++) if (tak[i] == 2) return i;
	return 4;
}
int main() {
//	freopen("input", "r", stdin);
	for (int i = 0 ;i < N; i++) scanf("%d", &a[i]);
	scanf("%d%d", &k, &d);
	k--;
	d--;
	int ans =0;
	for (int i = 1; i <= 6; i++) for (int j = i; j <= 6; j++)
		if (win(i, j) == 0) ans++;//, printf("%d %d\n", i, j);
	printf("%d\n", ans);
}
