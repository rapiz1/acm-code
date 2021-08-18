#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
typedef long long l;
ll left, right;
void input() {
  cin >> s;
  cin >> left;
  >> right;
}
int solve() { return 0; }
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %d", i, solve());
  }
}
