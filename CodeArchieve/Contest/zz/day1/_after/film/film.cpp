#include <cstdio>
#include <cstring>
#include <algorithm>
int n, mid, prev;
char s[100];
struct Real {
	int c;
	int rd() {
		int a, b = 0;
		if (scanf("%s", s) != 1) return 0;
		if (strchr(s, '.')) {
			sscanf(s, "%d.%d", &a, &b);
		}
		else sscanf(s, "%d", &a);
		c = a*100 + b*10;
		return 1;
	}
}a, b;
inline bool check() {
	int x = (prev + mid)*100ll/(n + mid) + 5;
	x = x/10*10;
	return x <= b.c;
}
int main() {
//	freopen("input", "r", stdin);
	freopen("film.in", "r", stdin);
	freopen("film.out", "w", stdout);
	while (a.rd()) {
		b.rd();
		scanf("%d", &n);
		int l = 0, r = 1e8;
		a.c += 5;
		a.c = std::min(a.c, 1000);
		prev = a.c*n/100;
		while (l < r) {
			mid = (l + r) >> 1;
//			printf("%d %d %d\n", l, mid, r);
			if (check()) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}
