#include <iostream>
using namespace std;
int main() {
	long long x;
	cin >> x;
	long long ans = x/11*2;
	x %= 11;	
	if (x > 0) ans++;
	if (x > 6) ans++;
	cout << ans;
}
