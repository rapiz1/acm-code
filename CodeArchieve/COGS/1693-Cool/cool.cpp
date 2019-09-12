#include <iostream>
#include <cstdio>
#include <algorithm>
#define file(x) "cool."#x
using namespace std;
const int N = 3010;
int f[N], n, m, a[N];
int X() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	cin >> n >> m;	
	for (int i = 0; i <= n; i++) cin >> a[i], f[i] = a[0]*(n + m);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			f[j] = max(f[j], f[j - i] + a[i] - a[0]);
	cout << f[n];
}
int enter = X();
int main() {
}
