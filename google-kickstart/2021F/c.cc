#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pa;
double sq(double x) { return x * x; }
double dis(pa x, pa y) {
  return sqrt(sq(x.first - y.first) + sq(x.second - y.second));
}
double round(pa x, pa y, pa z) { return dis(x, y) + dis(y, z) + dis(x, z); }
double area(pa x, pa y, pa z) {
  double a = dis(x, y), b = dis(x, z), c = dis(y, z);
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
bool eq(double x, double y) {
  static const double EPS = 1e-7;
  return abs(x - y) <= EPS;
}
bool in_angle(pa x, pa y, pa z, pa m) {
  return eq(area(x, y, m) + area(x, z, m) + area(y, z, m), area(x, y, z));
}
double solve() {
  double ans = -1;
  int n;
  cin >> n;
  pa target;
  vector<pa> pts;
  pts.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }
  cin >> target.first >> target.second;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        if (in_angle(pts[i], pts[j], pts[k], target)) {
          double rd = round(pts[i], pts[j], pts[k]);
          if (ans == -1)
            ans = rd;
          else
            ans = min(ans, rd);
        }
      }
  return ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    double ans = solve();
    if (ans < 0) {
      printf("Case #%d: IMPOSSIBLE\n", i);
    } else {
      printf("Case #%d: %lf\n", i, ans);
    }
  }
}
