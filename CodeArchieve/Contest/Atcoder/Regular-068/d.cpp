#include <cstdio>
#include <algorithm>
const int N = 3e5 + 10;
int a[N], n, m;
void add(int l, int r) {
	if (l > 0) a[l - 1]++; 
	a[r]--;
}
int main() {
	scanf("%d%d", &n, &m);
	while (n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int len = r - l + 1;
		len = std::min(len, l - 1);
		if (len >= l) {
			a[1]++, a[std::max(len, r) + 1]--;
		}
		else a[1]++, a[len + 1]--, a[l]++, a[r + 1]--;
		/*
		a[1]++;
		a[len + 1]--;
		a[l]++;
		a[r + 1]--;
		*/
	}
//	printf("%d\n", a[0]);
	for (int i = 1; i <= m; i++) printf("%d\n", a[i] += a[i - 1]);
}
