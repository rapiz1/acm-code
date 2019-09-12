#include <iostream>
const int N = 1e5 + 10;
using namespace std;
int n, cnt[N], odd, even;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= 1e5; i++) if (cnt[i]) {
		if (cnt[i]%2) odd++;
		else even++;
	}
	cout << odd + even - even%2;
}
