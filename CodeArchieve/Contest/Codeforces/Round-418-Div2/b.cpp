#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1010;
int a[N], b[N], n, c[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), c[a[i]]++;
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	for (int i = 1; i <= n; i++) {
		c[a[i]]--;
		int z = 0;
		for (int j = 1; j <= n; j++) z += c[j] == 0;
		if (z > 1) {c[a[i]]++; continue;}
		for (int j = 1; j <= n; j++) if (!c[j]) {
			int dif = 0;
			for (int k = 1; k <= n; k++) {
				if (k == i) dif += j != b[k];
				else dif += a[k] != b[k];
			}
			if (dif == 1) {
				for (int k = 1; k <= n; k++) {
					printf("%d ", k == i ? j : a[k]);
				}
				return 0;
			}
		}
		c[a[i]]++;
	}
	memset(c,0,sizeof c);
	for (int i = 1; i <= n; i++) std::swap(a[i], b[i]), c[a[i]]++;
	for (int i = 1; i <= n; i++) {
		c[a[i]]--;
		int z = 0;
		for (int j = 1; j <= n; j++) z += c[j] == 0;
		if (z > 1) {c[a[i]]++;continue;}
		for (int j = 1; j <= n; j++) if (!c[j]) {
			int dif = 0;
			for (int k = 1; k <= n; k++) {
				if (k == i) dif += j != b[k];
				else dif += a[k] != b[k];
			}
			if (dif == 1) {
				for (int k = 1; k <= n; k++) {
					printf("%d ", k == i ? j : a[k]);
				}
				return 0;
			}
		}
		c[a[i]]++;
	}

}
