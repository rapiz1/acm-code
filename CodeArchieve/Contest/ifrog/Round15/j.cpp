#include <cstdio>
#include <cmath>
const double PI = acos(-1);
struct Vec {
	double x, y;
	Vec(double a, double b){x=a, y=b;}
};
double dot(Vec a, Vec b) {return a.x*b.x + a.y*b.y;}
double cross(Vec a, Vec b) {return a.x*b.y - a.y*b.x;}
double len(Vec a) {return sqrt(dot(a, a));}
double angle(Vec a, Vec b) {return acos(dot(a, b)/len(a)/len(b));}
Vec operator+(Vec a, Vec b) {return Vec(a.x + b.x, a.y + b.y);}
Vec operator-(Vec a, Vec b) {return Vec(a.x - b.x, a.y - b.y);}
Vec operator*(Vec a, double b) {return Vec(a.x*b, a.y*b);}
Vec intersection(Vec P, Vec v, Vec Q, Vec w) {
	Vec u = P - Q;
	double t = cross(w, u)/cross(v, w);
	return P + v*t;
}
double a, b, c, d;
void solve() {
	Vec Q(1, 0), q(1, tan((180 - c - d)*PI/180));
	Vec O(0, 0), p(1, tan(b*PI/180));
	Vec E = intersection(O, p, Q, q);
	Vec i(1, tan((180 - d)*PI/180));
	Vec u(1, tan((a + b)*PI/180));
	Vec R = intersection(O, u, Q, i);
	double ans = angle(R - E, O - E);
	printf("%.2lf\n", ans*180/PI);
}
int main() {
//	freopen("input", "r", stdin);
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		solve();
	}
}
