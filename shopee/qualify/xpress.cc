#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
static const int N = 510;
vector<vector<int>> board, dis;
int n, m;
int inr(int x, int l, int r) { return x <= r && x >= l; }
typedef pair<int, int> pa;
unordered_map<int, vector<pa>> portal;

queue<pa> q;
void pushq(pa poi, queue<pa>& q, int distance) {
  auto [x, y] = poi;
  q.push(poi);
  dis[x][y] = distance;
  int pid = board[x][y];
  if (pid) {
    for (auto apoi : portal[pid]) {
      if (dis[apoi.first][apoi.second]) continue;
      dis[apoi.first][apoi.second] = distance;
      q.push(apoi);
    }
  }
}
void resize(vector<vector<int>>& mat, int n, int m) {
  mat.resize(n);
  for (auto& row : mat) {
    row.resize(m);
  }
}
int main() {
  cin >> n >> m;
  resize(dis, n, m);
  resize(board, n, m);
  if (!n || !m) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j]) {
        portal[board[i][j]].push_back({i, j});
      }
    }
  pushq({0, 0}, q, 1);

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        if (dx * dy == 0 && dx + dy != 0) {
          int nx = x + dx, ny = y + dy;
          if (inr(nx, 0, n - 1) && inr(ny, 0, m - 1) && !dis[nx][ny]) {
            pushq({nx, ny}, q, dis[x][y] + 1);
          }
        }
  }

  cout << dis[n - 1][m - 1] - 1;
}
