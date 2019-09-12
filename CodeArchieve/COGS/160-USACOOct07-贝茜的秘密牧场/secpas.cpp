#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int n, f[N];
int main() {
	freopen("secpas.in", "r", stdin);
	freopen("secpas.out", "w", stdout);
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= 4; i++) 
		for (int j = n; j; j--)
			for (int k = 1; k*k <= j; k++)
				f[j] += f[j - k*k];
	cout << f[n];
}
