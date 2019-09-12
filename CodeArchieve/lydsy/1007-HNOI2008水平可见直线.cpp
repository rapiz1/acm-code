#include <cstdio>
#include <algorithm>
const int N = 5e4 + 10;
const double eps = 1e-8;
inline int sgn(double a) {return a < -eps ? -1 : a > eps ? 1 : 0;}
struct Line {
	double k, b;
	int id;
	bool operator<(const Line& rhs)const {
		if (!sgn(k - rhs.k)) return b > rhs.b;
		else return k < rhs.k;
	}
}lines[N], sk[N];
double jiao(const Line& a, const Line& b){return (a.b - b.b)/(b.k - a.k);}
int n;
bool ans[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		double k, b;scanf("%lf%lf", &k, &b);
		lines[i] = (Line){k, b, i};
	}
	std::sort(lines + 1, lines + 1 + n);
	int top = 0;
	for (int i = 1; i <= n; i++) if (sgn(lines[i].k - lines[i - 1].k)) {
		while(top > 1 && jiao(sk[top - 1], lines[i]) <= jiao(sk[top - 1], sk[top - 2])) top--;
		sk[top++] = lines[i];
	}
	while(top) ans[sk[--top].id] = 1;
	for (int i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
}
