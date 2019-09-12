#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 60, L = 60;
int ans = 1e9, n, m, len[N], co[N][3];
char s[N][L];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		len[i] = strlen(s[i]);
		co[i][0] = co[i][1] = co[i][2] = 1e5;
		for (int j = 0; j < len[i]; j++) if (s[i][j] <= 'z' && s[i][j] >= 'a') co[i][1] = min(co[i][1], min(j, len[i] - j)); 
		else if (s[i][j] <= '9' && s[i][j] >= '0') co[i][0] = min(co[i][0], min(j, len[i] - j));
		else if (s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&') co[i][2] = min(co[i][2], min(j, len[i] - j));
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) for (int k = 1; k <= n; k++) if (k != i && k != j) ans = min(ans, co[i][0] + co[j][1] + co[k][2]);
	cout << ans;
}
