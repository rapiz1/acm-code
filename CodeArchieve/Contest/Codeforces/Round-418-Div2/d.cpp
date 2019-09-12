#include <cstdio>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstring>
const int N = 1010;
const double PI = acos(-1), eps = 1e-8;
int n;
double ans;
bool in[N][N];//to[x][y] = [x in y]
double sq(double x) {return x*x;}
struct Cir {
	int x, y, r;
	double s;
	inline double dis(const Cir& b)const {
		return sqrt(sq(b.x - x) + sq(b.y - y));
	}
	bool operator<(const Cir& b)const {return s > b.s;}
}st[N];
std::vector<int> a, b;
double cost(std::vector<int>& ss, int ci) {
	int sta = 1;
	double w = 0;
	for (int i = 0; i < (int)ss.size(); i++) if (in[ci][ss[i] > 0 ? ss[i] : -ss[i]]) sta*=-1;
	else if (in[ss[i] > 0 ? ss[i] : -ss[i]][ci]) {
		if (ss[i] > 0) w -= 2*st[ss[i]].s;
		else w += 2*st[-ss[i]].s;
	}
	w += st[ci].s*sta;
	return w;
}
double add(std::vector<int>& ss, int ci) {
	int sta = 1;
	double w = 0;
	for (int i = 0; i < (int)ss.size(); i++) if (in[ci][ss[i] > 0 ? ss[i] : -ss[i]]) sta*=-1;
	else if (in[ss[i] > 0 ? ss[i] : -ss[i]][ci]) {
		if (ss[i] > 0) w -= 2*st[ss[i]].s;
		else w += 2*st[-ss[i]].s;
		ss[i]*=-1;
	}
	w += st[ci].s*sta;
	ss.push_back(sta*ci);
	return w;
}
inline void solve() {
	a.clear();
	b.clear();
	memset(in, 0, sizeof in);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		in[i][j] = st[i].dis(st[j]) <= st[j].r - st[i].r + eps;
	double aa = 0, bb = 0;
	for (int i = 1; i <= n; i++) {
		double wa = cost(a, i), wb = cost(b, i);
		if (wa > wb) aa += add(a, i);
		else bb += add(b, i);
	}
	ans = std::max(ans, aa + bb);
}
int main() {
//	freopen("input", "r", stdin);
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &st[i].x, &st[i].y, &st[i].r);
		st[i].s = PI*sq(st[i].r);
	}
	std::sort(st + 1, st + 1 + n);
	solve();
	int T = 40;
	while (T--) {
		std::random_shuffle(st + 1, st + 1 + n);
		solve();
	}
	printf("%.8lf\n",ans);
}
