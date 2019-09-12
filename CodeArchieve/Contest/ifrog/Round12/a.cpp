#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;cin>>T;
	while (T--) {
		int n, x, d;
		cin >> n >> d >> x;
		int l = max(1, x - d), r = min(x + d, n);
		cout << r - l + 1 << endl;
	}
}
