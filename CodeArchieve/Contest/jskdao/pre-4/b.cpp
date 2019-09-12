#include <cstdio>
#include <algorithm>
int n, dx, dy, cnt;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (dx != x2 - x1 || dy != y2 - y1) cnt--;
		else cnt++;
		if (cnt <= 0) dx = x2 - x1, dy = y2 - y1, cnt = 1;
	}
	printf("%d %d\n", dx, dy);
}
