#include <bits/stdc++.h>
using namespace std;
class DetectSquares {
 public:
  static const int N = 1010;
  // int pts[N][N];
  unordered_map<int, int> col[N], row[N];
  DetectSquares() {
    // memset(pts, 0, sizeof pts);
  }

  void add(vector<int> point) {
    // pts[point[0]][point[1]]++;
    col[point[0]][point[1]]++;
    row[point[1]][point[0]]++;
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1];
    // typedef pair<int, int> pa;
    int ans = 0;
    for (auto e : row[y]) {
      if (!e.second) continue;
      int nx = e.first;
      int len = abs(nx - x);
      if (!len) continue;
      int ny = y - len;
      if (col[nx].count(ny) && col[x].count(ny)) {
        ans += col[nx][ny] * col[x][ny] * e.second;
      }
      ny = y + len;
      if (col[nx].count(ny) && col[x].count(ny)) {
        ans += col[nx][ny] * col[x][ny] * e.second;
      }
    }
    return ans;
  }
};
