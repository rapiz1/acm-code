#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int y, a, b, c;
		cin >> a >> b >> c;
		y = (c - 2*a)/4;
		cout << b - y << endl;
	}
}
