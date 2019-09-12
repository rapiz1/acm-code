#include <cstdio>
int main() {
	int n, a, c = 0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (!c) a = x;
		if (x == a) c++;
		else c--;
	}
	printf("%d\n", a);
}
