#include <cstdio>
#include <iostream>
#include <algorithm>
#define file(x) "charm." #x
using namespace std;
const int N = 3500, M = 13000;
int n, m, w[N], d[N], f[M];
int main() {
	freopen(file(in), "r", stdin), freopen(file(out), "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> d[i];
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + d[i]);
	cout << f[m];
}
