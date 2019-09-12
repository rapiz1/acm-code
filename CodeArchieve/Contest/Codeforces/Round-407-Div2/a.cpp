#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
long long ans;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ans += (x + k - 1)/k;
	}
	cout << (ans + 1)/2;
}
