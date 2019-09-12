#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
char a[N][N];
inline bool ck(int i, int j) {return 1 <= i && i <= n && 1 <= j && j <= m;}
bool solve() {
	cin >> n >> m;
	int cnt[2] = {};
	for (int i=  1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> a[i][j];
		if (a[i][j] != '.') cnt[a[i][j] == '2']++;
	}
	int win[2] = {};
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != '.') {
		for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx || dy) {
			int s, x, y;
			for (s = 0; ; s++) if (ck(x = i + s*dx, y = j + s*dy) && a[x][y] == a[i][j]) ;
			else break;
			s--;
			if (s >= 5) win[a[i][j] == '2']++;
			if (s > 9) return -1;
		}
	}
	if (win[0] && win[1]) return -1;
	if (win[0]) return ;
	else if(win[1]) return 1;
	else return 2;
}
int main() {
	freopen("input", "r", stdin);
	int T;cin >> T;
	while (T--) {
		int r = solve();
		if (r == -1)puts("fault");
		else if (r == 2) puts("other");
		else puts(r?"black":"white");
	}
}
