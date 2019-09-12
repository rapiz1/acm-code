#include <cstdio>
const int N = 1e5 + 10;
int n, m, arg[N], dam, num;
char op[N][10];
int calc(int x, int p){
	for (int i = 1; i <= n; i++) {
		int d = arg[i] >> p & 1;
		if (op[i][0] == 'O') x |= d;
		else if (op[i][0] == 'X') x ^= d;
		else if (op[i][0] == 'A') x &= d;
	}
	return x;
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) scanf("%s%d", op[i], arg + i);
	for (int i = 30; i >= 0; i--) {
		int t1 = calc(1, i), t0 = calc(0, i);
		if (t1 > t0 && (num | (1 << i)) <= m) num |= 1 << i, dam += t1 << i;
		else dam += t0 << i;
	}
	printf("%d", dam);
}
