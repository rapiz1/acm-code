#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
int n;
double v[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i]; 
  }
  sort(v + 1, v + 1 + n);
  for (int i = 2; i <= n; i++) {
    v[i] = (v[i] + v[i - 1])/2;
  }
  printf("%.5lf\n", v[n]);
}
