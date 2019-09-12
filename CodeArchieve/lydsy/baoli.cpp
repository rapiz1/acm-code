#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int main() {
	int n = 120, m = 6, cnt = 0;
	for (int i = 1; i <= n; i++) cnt += gcd(i, m) == 1;
	cout << cnt;
}
