#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 10007;
int rev[P], fac[P];
int comb(int n, int m) {
	if (n < m) return 0;
	if (n < P && m < P) return (ll)fac[n]*rev[m]*rev[n - m]%P;
	return (ll)comb(n/P, m/P)*comb(n%P, m%P)%P;
}
int main() {
	rev[0] = rev[1] = fac[0] = fac[1] = 1;
	for (int i = 2; i < P; i++) rev[i] = P - P/i*(ll)rev[P%i]%P;
	for (int i = 2; i < P; i++) fac[i] = fac[i - 1]*(ll)i%P, rev[i] = rev[i - 1]*(ll)rev[i]%P;
	int t; cin >> t;
	for (int n, m;t--;) cin >> n >> m, cout << comb(n, m) << endl;
}
