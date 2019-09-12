#include <cstdio>
#include <algorithm>
const int N = 1 << 17;
struct S{int l, i;double f;
	bool operator<(const S& b)const {return l*b.f < b.l*f;}
}a[N];
int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) scanf("%d%d%lf", &a[i].i, &a[i].l, &a[i].f);
		std::sort(a + 1, a + 1 + n);
		int x; scanf("%d", &x);
		printf("%d\n", a[x].i);
	}
}
