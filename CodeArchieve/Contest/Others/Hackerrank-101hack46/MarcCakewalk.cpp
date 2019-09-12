#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, a[1000];
bool cmp(int x, int y) {return x > y;}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	ll ans = 0;
	for (ll i = 1, d = 1; i <= n; i++, d <<= 1) ans += a[i]*d;
	cout << ans;
}
