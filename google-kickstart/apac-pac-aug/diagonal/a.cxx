#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n;
bool board[MAXN][MAXN];  // we want to make it all true
int flip[2 * MAXN];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      board[i][j] = x == '#';
    }
}

int get_primary_idx(int i, int j) {
  // 0, 0 -> N - 1
  // N-1, 0 -> 2N-2
  // N-2, 0 -> 2N-3
  // y, x -> (y-x) + N -1
  return (i - j) + n - 1;
}
int get_primary(int i, int j) { return flip[get_primary(i, j)]; }

int get_secondary_idx(int i, int j) { return get_primary(i, n - 1 - j); }
int get_secondary(int i, int j) { return flip[get_secondary_idx(i, j)]; }

int is_cell_settled(int i, int j) {
  return get_primary(i, j) != -1 && get_secondary(i, j) != -1;
}

bool all_black() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (get_stat(i, j) == false) return false;
  return true;
}

void test() {
  assert(get_secondary(0, 0) == 0);
  assert(get_secondary(0, n - 1) == n - 1);
  assert(get_secondary(n - 1, 0) == n - 1);
}

int get_stat(int i, int j) {
  return board[i][j] ^ get_primary(i, j) ^ get_secondary(i, j);
}

int work() {
  int c = 0;
  for (int t = 0; t < n * n; t++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
      }
    if (all_black()) {
      return c;
    }
  }
  return INT_MAX;
}

int solve() {
  memset(flip, -1, sizeof flip);
  flip[0] = 0;
  int answer = work();

  memset(flip, -1, sizeof flip);
  flip[0] = 1;
  answer = min(answer, work());

  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    // test();
    printf("Case #%d: %d\n", i, solve());
  }
}
