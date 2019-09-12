#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0) puts("NO");
	else if (abs(a - b) <= 1) puts("YES");
	else puts("NO");
}
