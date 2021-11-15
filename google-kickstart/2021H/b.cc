#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string p;
unordered_map<char, int> col;

int count(const vector<int> &v) {
  int c = 0;
  for (int i = 0, j = 0; i < v.size(); i = j + 1) {
    j = i;
    if (v[i] == 0) {
      continue;
    }
    while (j + 1 < v.size() && v[j + 1] == v[i]) j++;
    c++;
  }
  return c;
}

ll solve() {
  ll ans = 0;
  int n;
  cin >> n >> p;
  int mask[] = {1, 2, 4};
  for (auto mk : mask) {
    vector<int> now;
    for (auto c : p) {
      now.push_back((col[c] & mk) == mk);
    }
    ans += count(now);
  }
  // handle unpaint
  // vector<int> now;
  // for (auto c : p) now.push_back(c == 'U');
  // ans += count(now);
  return ans;
}
int main() {
  int k;
  cin >> k;
  col['U'] = 0b000;
  col['R'] = 0b001;
  col['Y'] = 0b010;
  col['O'] = 0b011;
  col['B'] = 0b100;
  col['P'] = 0b101;
  col['G'] = 0b110;
  col['A'] = 0b111;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
