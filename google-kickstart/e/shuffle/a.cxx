#include <bits/stdc++.h>
#define NOSOL "IMPOSSIBLE"
using namespace std;
string s;
static const int CHARSET = 256;
int chcount[CHARSET];
void input() { cin >> s; }
string solve() {
  memset(chcount, 0, sizeof chcount);

  string answer = "";
  int n = s.size();
  for (auto c : s) chcount[c]++;
  vector<pair<int, int>> vec;
  for (int i = 'a'; i <= 'z'; i++) {
    vec.push_back({chcount[i], i});
  }
  sort(vec.begin(), vec.end(), greater<pair<int, int>>());
  for (auto c : s) {
    bool fd = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i].second != c && vec[i].first > 0) {
        fd = 1;
        answer.push_back(vec[i].second);
        vec[i].first--;
        // cout << answer << endl;
        break;
      }
    }
    if (!fd) return NOSOL;
  }
  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %s\n", i, solve().c_str());
  }
}
