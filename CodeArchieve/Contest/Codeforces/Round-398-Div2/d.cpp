#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
int n, m, k, a[N], ans[N], tot;
struct MK {
	int i, d;
	bool operator<(const MK& b)const {return d < b.d;}
}b[N];
int main(){
//freopen("input", "r", stdin);
scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i].d), b[i].i = i;
	sort(b + 1, b + 1 + m);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) if (i > (a[i] + 1ll)*k) {
		puts("-1");
		return 0;
	}
	for (int i = 1, j = 0; i <= m; i++) {
		while (j + 1 <= n && a[j + 1] <= b[i].d) j++;
		if ((tot + 1 + j) <= (b[i].d + 1ll)*k) ans[++tot] = b[i].i;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
}
