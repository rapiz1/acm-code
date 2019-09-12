#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15, C = 1010;
int n, c, a[N], f[C];
int main() {
	freopen("change.in", "r", stdin);
	freopen("change.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	cin >> c >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= c; j++)
			f[j] = min(f[j], f[j - a[i]] + 1);
	cout << f[c];
}
