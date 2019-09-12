#include <cstdio>
#include <algorithm>
const int N = 5e5 + 10, M = 25;
struct T{int d, a, b, i;
	bool operator<(const T& x)const {return d < x.d || (d == x.d && b < x.b);}
	void rd(int ii) {scanf("%d%d%d", &a, &b, &d); i = ii;}
}a[N];
int n, m, ss[M][2];
bool so[M];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) a[i].rd(i);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1, j = 1; i <= n && j <= n; i++) {
		while (j <= n && a[j].d == a[i].d && a[i].b >= a[j].a) j++;
		if (j <= n && a[j].d == a[i].d && a[i].b < a[j].a) {
			so[a[i].d] = 1;
			ss[a[i].d][0] = a[i].i;
			ss[a[i].d][1] = a[j].i;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (so[i]) printf("TAK %d %d\n", ss[i][0], ss[i][1]);
		else puts("NIE");
	 }
}
