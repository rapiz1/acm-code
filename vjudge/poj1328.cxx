/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 13 Sep 2019 21:25:08 +0800
 */
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
typedef pair<double, double> P;
int n, d;
vector<P> x, uni;
int solve() {
  uni.clear();
  x.resize(n);
  for (auto& e : x) {
    cin >> e.first >> e.second;
  }
  for (auto& e: x) {
    double delta = d*d - pow(abs(e.second), 2);
    if (delta < 0) {
      return -1;
    } 
    else delta = sqrt(delta);
    e = P({e.first - delta, e.first + delta});
  }
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  for (auto i: x) {
    bool flag = 1;
    for (auto j: x) if (i != j) {
      if (i.first <= j.first && j.second <= i.second) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      uni.push_back(i);
    }
  }
  int ans = 0;
  double last = -2e9;
  for (auto x: uni) {
    if (x.first <= last && last <= x.second) {
      continue;
    }
    else {
      last = x.second;
      ans++;
    }
  }
  return ans;
}
int main() {
  int ks = 0;
  while (cin >> n >> d) {
    if (!n && !d) break;
    printf("Case %d: %d\n", ++ks, solve());
  }
}

