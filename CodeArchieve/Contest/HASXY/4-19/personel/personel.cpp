#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
const int N = 23, K = 20;
const double INF = 1e18;
int n, jiao[N], nd;
bool safe[1 << K];
double ave, f[N][1 << K], ww[1 << K];
struct Task{int l, r, w;
	Task(){};
	Task(int h, int m, int hh, int mm) {l = h*60 + m, r = hh*60 + mm; w = r - l + 1;}
	bool operator<(const Task& rhs)const {return l < rhs.l;}
}st[N];
double calc(int x) {
	double ret = 0;
	for (int i = 0; i < n; i++) if (x>>i&1) ret += st[i + 1].w;
	return (ret - ave)*(ret - ave);
}
bool check(int x) {
	for (int i = 0; i < n; i++) if ((x>>i&1) && (jiao[i + 1]&x)) return 0;
	return 1;
}
namespace Ans1 {
const int T = 60*24;
int s[2000], e[2000];
inline bool vaild(int lf) {
	for (int i = 1; i <= T; i++) {
		lf -= s[i];
		if (lf < 0) return 0;
		lf += e[i];
	}
	return 1;
}
}
void pt(int x){ 
	for (int i = 0; i < n; i++) printf("%d", x>>i&1);
}
void show(int i, int ss) {
			printf("f[%d][", i);
			pt(ss);
			printf("]=%.2lf\n", f[i][ss]);
}
void solve() {
	memset(jiao, 0, sizeof jiao);
	memset(Ans1::s, 0, sizeof Ans1::s);
	memset(Ans1::e, 0, sizeof Ans1::e);
	ave = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int h, m, hh, mm;
		scanf("%d:%d %d:%d", &h, &m, &hh, &mm);
		st[i] = Task(h, m, hh, mm);
		ave += st[i].w;
		Ans1::s[st[i].l]++;
		Ans1::e[st[i].r]++;
	}
	for (int i = 1; i <= n; i++) if (Ans1::vaild(i)) {nd = i;break;} 
	ave/=nd;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
		if (i != j && std::max(st[i].l, st[j].l) <= std::min(st[i].r, st[j].r)) jiao[i] = jiao[i]|(1<<(j - 1));
	for (int i = 0; i < 1 << n; i++) safe[i] = check(i), ww[i] = calc(i);
	for (int i = 0; i <= nd; i++) for (int j = 0; j < 1 << n; j++) f[i][j] = INF;
	f[0][0] = 0;
	for (int i = 1; i <= nd; i++) {
		for (int s = 0; s < 1 << n; s++) if (f[i - 1][s] != INF) {
			int rs = ((1 << n) - 1)^s;
//			puts("--");
//			show(i - 1, s);
			for (int ss = rs; ss; ss = (ss - 1)&rs)
			 	if (safe[ss])  {
//					show(i, s|ss);
					f[i][s|ss] = std::min(f[i][s|ss], f[i - 1][s] + ww[ss]);
				}
		}
	}
	printf("%d %.2lf\n", nd, sqrt(f[nd][(1 << n) - 1]/nd));
}
int main() {
	freopen("personnel.in", "r", stdin);
//	freopen("personnel.out", "w", stdout);
	int c; scanf("%d", &c);
	while (c--) solve();
}
