#include <iostream>
#include <algorithm>
using namespace std;
int a, b, k;
int main() {
	cin >> k >> a >> b;
	if (a < b) swap(a, b);
	if (a%k&&b/k == 0) cout << -1;
	else cout << a/k + b/k;
}
