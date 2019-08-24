#include <iostream>
using namespace std;
int n;
double a, ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans += 1/a;
  }
  printf("%.5lf", 1/ans);
}
