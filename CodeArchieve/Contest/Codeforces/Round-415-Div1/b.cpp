#include <cstdio>
int n, k;
char s[100];
int qu(int x, int y) {
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", s);
	return s[0] == 'T';
}
int get(int l, int r) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (r == l + 1) {
			if (qu(l, r)) r = l;
			else l = r;
		}
		else {
			int a = (r - l)/4 + 1;
			if (qu(l + a - 1, r - a + 1)) r = mid;
			else l = mid + 1;
		}
	}
	return l;
}
int main() {
	scanf("%d%d", &n, &k);
	int x = get(1, n), y;
	if (x == n) y = get(1, n - 1);
	else if (x == 1) y = get(2, n);
	else {
		int y1 = get(1, x - 1), y2 = get(x + 1, n);
		y = qu(y1, y2) ? y1 : y2;
	}
	printf("2 %d %d\n", x,y);
	fflush(stdout);
}
