#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
const int N = 1e5 + 10;
char buf[N], tmp[N];
int n;
int main() {
//	freopen("input", "r", stdin);
	for (int ch; (ch = getchar()) != EOF;) {
		buf[++n] = ch;
	}
	for (int i = 1, j; i <= n; i += j) {
		if (isalpha(buf[i])) {
			sscanf(buf + i, "%s%n", tmp, &j);
			for (int p = 0, q = j - 1; p < q; p++, q--) std::swap(buf[i + p], buf[i + q]);
		}
		else j = 1;
	}
	printf("%s", buf + 1);
}
