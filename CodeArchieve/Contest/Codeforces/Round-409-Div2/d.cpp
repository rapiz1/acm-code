#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const double eps = 1e-8;
struct Vec {double x, y;
	Vec(double a = 0, double b = 0){x = a, y = b;}
}poi[N];
Vec operator-(const Vec& a, const Vec& b){return Vec(a.x - b.x, a.y - b.y);}
double len(Vec a) {return sqrt(a.x*a.x + a.y*a.y);}
double cross(Vec a, Vec b) {return a.x*b.y - a.y*b.x;}
double p2line(Vec p, Vec a, Vec b) {
	Vec v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2))/len(v1);
}
int n;
inline int sgn(double x) {
	if (x > eps) return 1;
	else if (x < -eps) return -1;
	else return 0;
}
double sq(double x) {return x*x;}
double ans = 1e18;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf%lf", &poi[i].x, &poi[i].y);
	poi[n + 1] = poi[1], poi[n + 2] = poi[2];
	for (int i = 1; i <= n; i++) {
		double dis = p2line(poi[i + 1], poi[i], poi[i + 2]);
		ans = min(ans, dis/2);
	}
	printf("%lf\n", ans);
}
