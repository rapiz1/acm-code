#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 10;
int n, phi[N], pri = 1;
long long ans;
int main() {
	cin >> n;
	n--;
	phi[1] = 1;
	for (int i = 2; i <= n; i++) if (!phi[i]) {
		phi[i] = i;
		pri++;
		for (int j = i; j <= n; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i - 1);
		}
	}
	for (int i = 1; i <= n; i++) ans += phi[i];
	if (n) cout << ans*2 + 1;
	else cout << 0;
}
