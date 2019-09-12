#include <bits/stdc++.h>
using namespace std;
const int N = 4000001;
int n, phi[N];
long long f[N];
int main() {
//	freopen("input" ,"r", stdin);
	phi[1] = 1;	
	for (int i = 2; i < N; i++) if (!phi[i]) {
		for (int j = i; j < N; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] =  phi[j]/i*(i - 1);
		}
	}
	for (int i = 1; i < N; i++)
		for (int j = i + i; j < N; j += i) f[j] += i*phi[j/i];
	for (int i = 1; i < N; i++) f[i] += f[i - 1];
	while ((cin >> n), n) cout << f[n] << endl;
}
