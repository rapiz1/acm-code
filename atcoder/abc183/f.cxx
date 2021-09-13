#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int p[MAXN];
map<int, int> *contains[MAXN];
int n, q;
int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
void merge(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return;
  p[b] = a;
  auto big = contains[a], small = contains[b];
  if (big->size() < small->size()) swap(big, small);
  for (auto x : *small) {
    (*big)[x.first] += x.second;
  }
  contains[a] = big;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    contains[i] = new map<int, int>();
    (*contains[i])[x] = 1;
    p[i] = i;
  }
  for (int i = 1; i <= q; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1) {
      merge(a, b);
    } else {
      // op == 2
      cout << (*contains[find(a)])[b] << endl;
    }
  }
}
