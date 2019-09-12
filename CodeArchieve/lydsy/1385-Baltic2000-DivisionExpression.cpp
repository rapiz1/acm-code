#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll mo, ch;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> ch >> mo;
		mo /= gcd(ch, mo);
		for (int i = 3; i <= n; i++) {
			ll x; cin >> x;
			mo /= gcd(x, mo);
		}
		puts(mo == 1?"YES":"NO");
	}
}
