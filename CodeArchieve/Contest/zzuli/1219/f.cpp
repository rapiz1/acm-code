#include <bits/stdc++.h>
using namespace std;
char s[1000], dig;
int n, k;
int count(int x) {
	int r = 0;
	for (;x;x>>=1) r += x&1;
	return r;
}
void solve() {
	do fgets(s, 1000, stdin); while (s[0] == '\n');
	int p = 0;
	n = 0, k = 0;
	for (;s[p] != ' '; p++) if (isdigit(s[p])) n = n*10 + s[p] - '0';
	p++;
	sscanf(s + p, "%d", &k);
//	cout << n << " " << k << endl;
	long long ans = 0;
	while (count(n) > k) {
		ans += n&-n;
		n += n&-n;	
	}
	cout << ans << endl;
}
int main() {
//	freopen("input", "r", stdin);
	int t;
	cin >> t;
	while (t--) solve();
}
