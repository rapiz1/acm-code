#include <iostream>
using namespace std;
string a, s;
int main() {
  cin >> a >> s;
  int x = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    x = x*10 + a[i] - '0';
  }
  cout << (x >= 3200 ? s : string("red"));
}
