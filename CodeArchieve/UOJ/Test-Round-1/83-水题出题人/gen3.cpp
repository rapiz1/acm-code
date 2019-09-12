#include <cstdio>
#include <cstdlib>
#include <vector>
const int L = 1e9, N = 3e4 + 10;
int b[N], n;
std::vector<int> a;
void build() {
	for (int i = 1; i <= n; i++) {
		int mid = i + n >> 1;
		std::swap(a[i], a[mid]);
	}
	for (int i = 1; i <= n; i++) b[a[i]] = i;
}
int main() {
	n = 1984;
	printf("%d\n", n);
	a.push_back(0);
	for (int i = 1; i <= n; i++) a.push_back(i);
	build();
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
}
