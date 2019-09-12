#include <cstdio>
#include <algorithm>
using std::max;
const int U = 1e5 + 1;
int a[U], n, r = 1;
int main() {
	scanf("%d", &n);
	while (n--){
		int t;
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 2; i < U; i++) {
		int s = 0;
		for (int j = i; j < U; j += i) s += a[j];
		r = max(r, s);
	}
	printf("%d", r);
}
