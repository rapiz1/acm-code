#include <cstdio>
typedef long long ll;
int n, phi;
ll qpm(ll x, ll r){
	ll s = 1;
	while (r) {
		if (r&1) 	s = s*x%n;
		r >>= 1, x = x*x%n;
	}
	return s;
}
bool check(int a) {
	ll x = phi;
	for (int i = 2; i*i <= x; i++) if (x%i == 0) {
		if (qpm(a, phi/i) == 1) return false;
		while (x%i == 0) x /= i;
	}
	if (x > 1) if (qpm(a, phi/x) == 1) return false;
	return true;
}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int main() {
	scanf("%d", &n);
	phi = n;
	int x = n;
	for (int i = 2; i*i <= x; i++) if (x%i == 0) {
		phi = phi/i*(i - 1);
		while (x%i == 0) x /= i;
	}
	if (x > 1) phi = phi/x*(x - 1);
//#define DBG
#ifdef DBG
	printf("\nphi : %d\n", phi);
#endif
	for (int i = 2; i < n; i++) if (gcd(i, n) == 1 && check(i)) {
		printf("%d", i);
		return 0;	
	}
}
