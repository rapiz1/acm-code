#include <cstdio>
#include <algorithm>
const int N = 1e3 + 10;
struct J{int t, w, i;
	bool operator<(const J& b)const {return b.t*w > t*b.w || (b.t*w == t*b.w && i < b.i);}
}a[N];
int n;
int calc(int* f) {
	int s = 0;
	for (int i = 1, p = 0; i <= n; p += a[f[i++]].t) s += p*a[f[i]].w;
	return s;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int ks = 1; ks <= T; ks++) {
		if (ks != 1) putchar('\n');
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].t, &a[i].w),a[i].i = i;
//		int f[]={2, 1, 3, 4, 0, 0};
//		printf("%d", calc(f));
		std::sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			printf("%d", a[i].i);
			if (i != n) putchar(' ');
		}
		putchar('\n');
	}
}
