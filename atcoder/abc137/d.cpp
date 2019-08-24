#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long ans = 0;
struct Job {
  int a, b;
  inline int deadline()const {
    return m - a + 1;
  }
  bool operator<(const Job& rhs)const {
    if (deadline() != rhs.deadline()) {
      return deadline() < rhs.deadline();
    }
    else {
      return b > rhs.b;
    }
  }
}jobs[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> jobs[i].a >> jobs[i].b;
  }
  sort(jobs+1, jobs+1+n);
  int day = 1;
  for (int i = 1; i <=n; i++) {
    printf("jobs#%d deadline:\t%d value:\t%d\n", i, jobs[i].deadline(), jobs[i].b);
  }
  for (int i = 1; i <= n; i++) {
    if (day > m) break;
    if (jobs[i].deadline() < day) continue;
    day++;
    ans += jobs[i].b;
  }
  cout << ans;
}
