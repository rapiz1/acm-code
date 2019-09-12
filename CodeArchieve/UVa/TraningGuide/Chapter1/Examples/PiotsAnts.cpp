#include <cstdio>
#include <algorithm>
const int N = 1e4 + 10;
int T, n, t, l, p[N], ll[N], d[N], np[N], lp[N], ap[N], ad[N];
bool cmp(int i, int j) {return p[i] < p[j];}
bool cmp2(int i, int j) {return np[i] < np[j];}
char buf[2];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &T);
	for (int ks = 1; ks <= T; ks++) {
		scanf("%d%d%d", &l, &t, &n);
		for (int i = 1; i <= n; i++) 	{
			scanf("%d%s", &p[i], buf);
		 	lp[i] = ll[i] = i;
		 	d[i] = buf[0] == 'R'; // 0 for left, 1 for right
			np[i] = p[i] + (d[i] ? 1: -1)*t;
		}
		std::sort(ll + 1, ll + 1 + n, cmp);
		std::sort(lp + 1, lp + 1 + n, cmp2);
		for (int i = 1; i <= n; i++) {
			int x = lp[i];
			ap[ll[i]] = np[x];
			ad[ll[i]] = d[x];
			for (int dd = -1; dd <= 1; dd += 2) if (i + dd <= n && i + dd >= 1 && np[x] == np[lp[i + dd]]) ad[ll[i]] = 2;
		}
		printf("Case #%d:\n", ks);
		for (int i = 1; i <= n; i++) if (ap[i] > l || ap[i] < 0) puts("Fell off");
		else {
			printf("%d ", ap[i]);
			if (ad[i] == 1) printf("R");
			else if (ad[i] == 2) printf("Turning");
			else printf("L");
			putchar('\n');
		}
		puts("");
	}
}
