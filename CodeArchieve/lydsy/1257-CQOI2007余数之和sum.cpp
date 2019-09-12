#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int n, k;
ll ans;
int bis(int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >>1;
		if (k/mid >= x) l = mid;
		else r = mid - 1;
	}
	return l;
}
int main() {
	//freopen("input", "r", stdin);
	cin >> n >> k;
	ans = (ll)n*k;
	for (int x = k, p = 1; x && p <= n; ) {
		int e = bis(x);
		ans -= (e - p + 1ll)*(p + e)/2*x;
//		printf("%d, %d : %d\n", p, e, x);
		p = e + 1;
		x = k/p;
	}
	cout << ans;
}
