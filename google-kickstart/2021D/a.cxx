#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 4;
int num[MAXN][MAXN];
int n;
int main() {
  int t;
  cin >> t;
  for (int ks = 1; ks <= t; ks++) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) continue;
        cin >> num[i][j];
      }
    unordered_map<int, int> count;
    int s = num[0][0] + num[2][2];
    if (s % 2 == 0) count[s / 2]++;

    s = num[0][2] + num[2][0];
    if (s % 2 == 0) count[s / 2]++;

    s = num[1][0] + num[1][2];
    if (s % 2 == 0) count[s / 2]++;

    s = num[0][1] + num[2][1];
    if (s % 2 == 0) count[s / 2]++;

    int maxc = 0, answer = -1;
    for (auto p : count) {
      if (p.second > maxc) {
        maxc = p.second;
        answer = p.first;
      }
    }

    int oc = 0;
    if (num[0][0] + num[0][2] == 2 * num[0][1]) oc++;
    if (num[2][0] + num[2][2] == 2 * num[2][1]) oc++;

    if (num[0][0] + num[2][0] == 2 * num[1][0]) oc++;
    if (num[0][2] + num[2][2] == 2 * num[1][2]) oc++;
    // cerr << "ans:" << answer << "maxc " << maxc << " oc:" << oc << endl;
    printf("Case #%d: %d\n", ks, maxc + oc);
  }
}
