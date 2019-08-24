#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
string str[N];
int n;
ll ans=0;
char buf[100];
int cmp(const void* a, const void* b) {
    return *((char*)a) - *((char*)b);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
      scanf("%s", buf);
      int len = strlen(buf);
      qsort(buf, len, sizeof(char), cmp);
      str[i] = string(buf);
  }
  sort(str + 1, str + n+1);
  int i = 1, j = 1;
  for (;i<=n; i=j+1) {
      while (j+1 <= n && str[i] == str[j+1]) {
          j++;
      }
      ll d = j - i + 1;
      ans += d*(d-1)/2;
  }
  cout << ans;
}
