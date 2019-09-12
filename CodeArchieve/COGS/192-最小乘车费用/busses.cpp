#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int n, a[14], f[N];
int main() {
	freopen("busses.in", "r", stdin);
	freopen("busses.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= 10; i++) cin >> a[i];
	cin >> n;
	f[0] = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = i; j <= n; j++)
			f[j] = min(f[j], f[j - i] + a[i]);	
	cout << f[n];
}
