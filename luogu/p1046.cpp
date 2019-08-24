#include <iostream>
#include <array>
using namespace std;
int main() {
  array<int, 10> hei;
  int h;
  for (auto& x : hei) cin >> x;
  cin >> h;
  int ans = 0;
  for (auto x: hei) {
    ans += h + 30 >= x;
  }
  cout << ans;
}
