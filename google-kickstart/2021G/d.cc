#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int n, A;
  cin >> n >> A;
  if (n == 3) {
    printf("POSSIBLE\n");
    printf("0 0\n1 0\n0 %d\n", A);
  } else if (n == 4) {
    if (A == 1) {
      printf("IMPOSSIBLE\n");
      return;
    }
    printf("POSSIBLE\n");
    if (A % 2 == 0) {
      A /= 2;
      printf("0 0\n1 0\n1 %d\n0 %d\n", A, A);
    } else {
      int x = A - 2;
      printf("0 0\n%d 0\n1 1\n0 1\n", x + 1);
    }
  } else if (n == 5) {
    if (A <= 2) {
      printf("IMPOSSIBLE\n");
      return;
    }
    printf("POSSIBLE\n");
    int h = A - 2;
    printf("0 0\n1 0\n%d 2\n1 1\n0 1\n", h + 1);
  }
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
