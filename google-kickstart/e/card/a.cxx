#include <bits/stdc++.h>
using namespace std;
int n;
void input() { cin >> n; }
const int MAXN = 1e6 + 1;
double fac[MAXN];
double solve() {
  double answer = 0;
  // i
  // P(all numbers preceding in a permutation is smaller)*i
  // good permutations are:
  // for number i in pos x, which x in 1...i
  // good numbers are [1,i-1]. select x-1 of them to form a perm
  // C(x-1, i-1)*A(x-1,x-1) = A(x-1, i-1)
  // contributatoin: A(x-1,i-1)/A(n,n)
  // accumulate it
  // input n=2:
  // i=1: x=1: A(0, 0)/A(2,2) = 1/2 = 0.5
  // i=2: x=1: A(0, 1)/A(2,2) = 1/2 = 0.5. x=2: A(1,1)/A(2,2) = 1/2 = 0.5
  for (int i = 1; i <= n; i++) {
    double seg = 0;
    double s = fac[i - 1] / fac[n];
    for (int x = 1; x <= i; x++) seg += s * fac[n - x] / fac[i - x];
    answer += seg;
  }
  return answer;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i;
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    // input();
    n = i;
    printf("Case #%d: %lf\n", i, solve());
  }
}
