#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
void exgcd(ll a, ll b, ll&d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
int main() {
	ll n, m, x, y, d;
	cin >> n >> m;
	exgcd(n, m, d, x, y);
	cout << mod(x, m/d);
}
