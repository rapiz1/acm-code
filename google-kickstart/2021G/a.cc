#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool solve() {
  ll n, d, c, m;
  cin >> n >> d >> c >> m;
  cin >> s;
  int len = 0;
  for (auto e : s) {
    if (e == 'C') {
      if (c == 0) break;
      c--;
    } else if (e == 'D') {
      if (d == 0) break;
      d--;
      c += m;
    }
    len++;
  }
  int last_dog = -1;
  for (int i = 0; i < n; i++)
    if (s[i] == 'D') last_dog = i;
  return len > last_dog;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: ", i);
    cout << (solve() ? "YES" : "NO") << endl;
  }
}
