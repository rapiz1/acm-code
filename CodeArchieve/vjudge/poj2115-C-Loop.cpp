#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) x = 1, y = 0, d = a;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
int main() {
//	freopen("input", "r", stdin);
	ll a, b, c, k, m;
	while ((cin >> a >> b >> c >> k), (a + b + c + k != 0)) {
		m = 1;
		for (int i = 1; i <= k; i++) m*=2;
		ll x, y, d;
		exgcd(c, m, d, x, y);	
		if ((b - a)%d) puts("FOREVER");
		else {
			x = mod((b-a)/d*x, m/d);
			printf("%lld\n", x);
		}
	}
}
