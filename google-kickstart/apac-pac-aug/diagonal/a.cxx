#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n;
char board[MAXN][MAXN];
bool flip[2 * MAXN];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];
}

int solve() {
  int answer = min(work(0), work(1));
  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %d\n", i, solve());
  }
}
