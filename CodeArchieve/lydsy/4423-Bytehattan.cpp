#include <cstdio>
const int N = 1510, K = N*N;
int n, k, p[K];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int zip(int x, int y) {return x*(n + 1) + y;}
char cmd[3];
int main() {
	bool f = 1;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= zip(n, n); i++) p[i] = i;
	for (int i = 0; i <= n; i++) {
		p[find(zip(0, i))] = find(zip(0, i + 1)), p[find(zip(n, i))] = find(zip(n, i + 1));
		p[find(zip(i, 0))] = find(zip(i + 1, 0)), p[find(zip(i, n))] = find(zip(i + 1, n));
	}
	while (k--) {
		int x, y;
		if (f) scanf("%d%d%s%*d%*d%*s", &x, &y, cmd);
		else scanf("%*d%*d%*s%d%d%s", &x, &y, cmd);
		if (cmd[0] == 'E') {
			int a = zip(x, y - 1), b = zip(x, y);
			if (find(a) == find(b)) f = 0;
			else f = 1,  p[find(a)] = find(b);
		}
		else {
			int a = zip(x - 1, y), b = zip(x, y);
			if (find(a) == find(b)) f = 0;
			else f = 1, p[find(a)] = find(b);
		}
		puts(f ? "TAK" : "NIE");
	}
}
