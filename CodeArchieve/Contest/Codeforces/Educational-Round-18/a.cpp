#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, num;
long long a[N], len = 3e9;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i =2; i <= n; i++) {
		long long la = a[i] - a[i - 1];
		if (la < len) len = la, num = 1;
		else if (la == len) num++;
	}
	cout << len << " " << num;
}
