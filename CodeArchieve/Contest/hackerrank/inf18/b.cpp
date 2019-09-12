#include <iostream>
#include <cmath>
using namespace std;
long long a, b, c;
int main() {
//	freopen("input", "r", stdin);
	cin >> a;
	a = a*a;
	for (long long i = 1; i*i <= a; i++) if (a%i == 0) {
		long long c = (i + a/i);
		if (c%2) continue;
		c/=2;
		cout << int(sqrt(a)) << " " << (long long)(sqrt((long double)c*c - a) + 0.4) << " " << c;
		return 0;
	}
}
