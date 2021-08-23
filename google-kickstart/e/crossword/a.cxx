#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, m;
string board[MAXN];

// union-find set structure
int p[MAXN * MAXN];
int rep[MAXN * MAXN];
int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
void merge(int x, int y) {
  int a = find(x), b = find(y);
  p[a] = b;
  // printf("merging %c %c\n", rep[a], rep[b]);
  rep[b] = rep[a] ? rep[a] : rep[b];
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];
}

int get_idx(int i, int j) { return i * m + j; }
int solve() {
  int answer = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int k = get_idx(i, j);
      p[k] = k;
      rep[k] = 0;
      if (board[i][j] != '#' && board[i][j] != '.') rep[k] = board[i][j];
      answer -= bool(rep[k]);
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '#') continue;
      int k = j;
      while (k + 1 < m && board[i][k + 1] != '#') k++;
      for (int t = 0; t < k; t++) {
        int l = j + t, r = k - t;
        if (l >= r) break;
        merge(get_idx(i, l), get_idx(i, r));
        /*
        printf("merging %d,%d with %d,%d, rep=%c\n", i, l, i, r,
               rep[find(get_idx(i, l))]);
               */
      }
      j = k;
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (board[i][j] == '#') continue;
      int k = i;
      while (k + 1 < n && board[k + 1][j] != '#') k++;
      for (int t = 0; t < k; t++) {
        int l = i + t, r = k - t;
        if (l >= r) break;
        merge(get_idx(l, j), get_idx(r, j));
      }
      i = k;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) answer += bool(rep[find(get_idx(i, j))]);
  cout << answer << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '#')
        cout << '#';
      else {
        char c = rep[find(get_idx(i, j))];
        if (!c) c = '.';
        cout << c;
      }
      if (j == m - 1) cout << endl;
    }
  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: ", i);
    solve();
  }
}
