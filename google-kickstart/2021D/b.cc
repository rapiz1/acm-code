#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
ll l[MAXN], r[MAXN], c, diff[MAXN * 2];
ll solve() {
  int n;
  cin >> n >> c;
  vector<ll> allpos;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    allpos.push_back(l[i]);
    allpos.push_back(r[i]);
  }
  sort(allpos.begin(), allpos.end());
  allpos.resize(unique(allpos.begin(), allpos.end()) - allpos.begin());
  unordered_map<ll, int> pos2id;
  for (int i = 0; i < allpos.size(); i++) pos2id[allpos[i]] = i, diff[i] = 0;
  for (int i = 0; i < n; i++) {
    int lid = pos2id[l[i]], rid = pos2id[r[i]];
    diff[lid + 1]++;
    diff[rid]--;
  }
  vector<ll> counts;
  counts.reserve(allpos.size());
  for (int i = 1; i < allpos.size(); i++) {
    diff[i] += diff[i - 1];
    counts.push_back(diff[i]);
  }
  counts.push_back(diff[0]);
  sort(counts.begin(), counts.end(), less<ll>{});
  ll answer = 0;
  for (int i = 0; i < c; i++) answer += counts[i];
  return answer;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
