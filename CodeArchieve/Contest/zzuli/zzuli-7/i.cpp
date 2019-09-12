#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n, m;
char s[N][N], o[N][N];
void rot() {
	memset(o, 0, sizeof o);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) o[j][n - i + 1]= s[i][j];
	std::swap(n, m);
	memcpy(s, o, sizeof s);
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> (s[i] + 1);
	int a;cin >> a;
	if (a == 0) ;
	else if (a == 90) rot();
	else if (a == 180) rot(), rot();
	else if (a == 270) rot(), rot(), rot();
	for (int i = 1; i <= n; i++) cout << (s[i] + 1) << endl;
}
int main() {
//	freopen("input", "r", stdin);
	int T;cin >> T;
	while (T--) solve(); 
}
