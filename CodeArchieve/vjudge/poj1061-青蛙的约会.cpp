#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= x*(a/b);
}
ll mod(ll x, ll y) {
	if (x>0) return x%y;
	else return x + (-x + y - 1)/y*y;
}
int main() {
//	freopen("input", "r", stdin);
	ll a, b, n, m, l;
	cin >> a >> b >> m >> n >> l;
	ll x, y, d;
	if (m < n) std::swap(a, b), std::swap(m, n);
	exgcd(m - n, l, d, x, y);
	if ((b - a)%d) {
		puts("Impossible");
	}
	else {
		x = mod((b - a)/d*x, l/d);
		cout << x;
	}
}
