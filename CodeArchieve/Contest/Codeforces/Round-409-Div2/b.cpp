#include <bits/stdc++.h>
using namespace std;
const int L = 110;
char a[L], c[L], b[L];
int n;
int main() {
	scanf("%s%s", a, c);
	n = strlen(a);
	for (int i = 0; i < n; i++) {
		if (c[i] > a[i]) {
			puts("-1");
			return 0;
		}
		else b[i] = c[i];
	}
	puts(b);
}
