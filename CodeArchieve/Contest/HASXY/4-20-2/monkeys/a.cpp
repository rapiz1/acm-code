#include <cstdio>
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int main() {
	int n = 1000000;
	for (int i = 1; i <= n; i++) if (gcd(i, i - 1) != 1) printf("%d %d %d\n", i, i - 1, gcd(i ,i - 1));
}
