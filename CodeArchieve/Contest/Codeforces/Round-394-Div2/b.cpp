#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 120;
int n, a[N], b[N], l;
int main() {
//	freopen("input", "r", stdin);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int x = l - a[n] + a[1], y = l - b[n] + b[1];
	for (int i = n; i; i--) a[i] -= a[i-1], b[i] -= b[i-1];
	a[1] = x, b[1] = y;
	for (int i = 1; i <= n; i++) b[i + n] = b[i];
	for (int i = 0; i < n; i++) {
		bool f = 1;
		for (int j = 1; j <= n; j++) if (a[j] != b[i + j]) {
			f = 0;
			break;
		}
		if (f) {
//			printf("!%d\n", i);
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}
