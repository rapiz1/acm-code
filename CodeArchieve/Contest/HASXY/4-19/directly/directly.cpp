#include <cstdio>
int x, y, dx, dy;
void rot() {
	if (dx == 0 && dy == 1) dx = 1, dy = 0;
	else if (dx == 1 && dy == 0) dx = 0, dy = -1;
	else if (dx == 0 && dy == -1) dx = -1, dy = 0;
	else if (dx == -1 && dy == 0) dx = 0, dy = 1;
}
void z(int a, int b) {
	if (a <= 0 || b <= 0) return;
	x += dx, y += dy;
	z(a - b, b);
	rot();
	z(b - a, a);
}
void solve() {
	int a, b; scanf("%d%d", &a, &b);
	x = y = 0, dx = 0, dy = 1;
	z(a, b);
	printf("%d %d\n", x, y);
}
int main() {
    freopen("directly.in", "r", stdin);
    freopen("directly.out", "w", stdout);
	int c; scanf("%d", &c);
	while (c--) solve();
}
