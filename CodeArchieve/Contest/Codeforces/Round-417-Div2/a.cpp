#include <iostream>
using namespace std;
const int N = 5;
int a[N][N], n = 4;
int main() {
//	freopen("input", "r", stdin);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	bool f = 0;
	for (int i = 0; i < n; i++) if (a[i][3]) {
		if (a[i][0] || a[i][1] || a[i][2]) f = 1;
		int j = (i + 1)%4;
		if (a[j][0]) f = 1;
		j = (j + 1)%4;
		if (a[j][1]) f = 1;
		j = (j + 1)%4;
		if (a[j][2]) f = 1;
	}
	puts(f ? "YES" : "NO");
}
