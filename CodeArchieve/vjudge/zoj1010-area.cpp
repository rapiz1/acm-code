#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const double eps = 1e-8;
struct Vec {double x, y;
	Vec(double a = 0, double b = 0){x = a, y = b;}
}po[N];
Vec operator-(Vec a, Vec b) {return Vec(a.x - b.x, a.y - b.y);}
int sgn(double x) {return x > eps ? 1 : x < -eps ? -1 : 0;}
double det(Vec a, Vec b) {return a.x*b.y - a.y*b.x;}
double dot(Vec a, Vec b) {return a.x*b.x + a.y*b.y;}
bool onSegment(Vec p, Vec a, Vec b) {return !sgn(det(p - a, a - b)) && sgn(dot(p - a, p - b)) <= 0;}
bool intersection(Vec a1, Vec a2, Vec b1, Vec b2) {
	double c1 = det(b1 - a2, a1 - a2), c2 = det(b2 - a2, a1 - a2),
				 c3 = det(a1 - b2, b1 - b2), c4 = det(a2 - b2, b1 - b2);
	return (sgn(c1)*sgn(c2) < 0 && sgn(c3)*sgn(c4) < 0) || onSegment(a1, b1, b2) || onSegment(a2, b1, b2);
}
int main() {
//	freopen("input", "r", stdin);
	int n;
	int idx = 0;
	while (scanf("%d", &n), n) {
		double ans = 0;
		for (int i = 1; i <= n; i++) scanf("%lf%lf", &po[i].x, &po[i].y);
		bool flag = 0;
		po[n + 1] = po[1];
		if (n > 3) for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) 
				if (min(abs(i - j), n - abs(i - j)) > 1 && intersection(po[i], po[i + 1], po[j], po[j + 1])) {flag =1;break;}
		}
		else if (n < 3) flag = 1;
		for (int i = 2; i < n; i++) ans += det(po[i + 1] - po[1], po[i] - po[1]);
		if (idx) putchar('\n');
		printf("Figure %d: ", ++idx);
		if (flag) printf("Impossible\n");
		else printf("%.2lf\n", fabs(ans)/2);
	}
}
