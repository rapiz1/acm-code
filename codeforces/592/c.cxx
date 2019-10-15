/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 15 Oct 2019 20:39:42 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
void ex_gcd(ll a,ll b,ll& d,ll& x,ll& y){
	if(b==0) d=a,x=1,y=0;
	else {
		ex_gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
ll n, p, d, w;
int main() {
	cin >> n >> p >> w >> d;
	ll gcd, x, y;
	ex_gcd(w, d, gcd, x, y);
	if (p%gcd) {
		cout << -1 << endl;
		return 0;
	}
	else {
		ll tmp;
		ex_gcd(w/gcd, d/gcd, tmp, x, y);
		x *= p/gcd;
		y *= p/gcd;

		tmp = x/(gcd*d);
		x -= tmp*gcd*d;
		y += tmp*gcd*w;

		if (x + y <= n && x >= 0 && y >= 0) {
			cout << x << " " << y << " " << (n - x - y) << endl;
			return 0;
		}

		tmp = y/(gcd*w);
		x += tmp*gcd*d;
		y -= tmp*gcd*w;

		if (x + y <= n && x >= 0 && y >= 0) {
			cout << x << " " << y <<  " " << (n - x - y) << endl;
			return 0;
		}
	}
	cout << -1;
}

