#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> c;
unordered_map<string, int> f;
string a, b;
void tolower(string& x) {
  for (auto& ch: x) {
    ch = tolower(ch);
  }
}
int main() {
  cin >> a;
  tolower(a);
  string s;
  cin.ignore();
  getline(cin, s);
  tolower(s);
  stringstream ss(s);
  while (ss >> b) {
    if (!c[b]) {
      f[b] = int(ss.tellg()) - b.size();
    }
    c[b]++;
  }
  if (c[a]) {
    cout << c[a] << " " << f[a];
  }
  else {
    cout << -1;
  }
}
