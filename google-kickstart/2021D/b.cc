#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
ll l[MAXN], r[MAXN], c;
ll solve() {
  int n;
  cin >> n >> c;
  vector<ll> allpos, diff;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    allpos.push_back(l[i]);
    allpos.push_back(l[i] + 1);
    allpos.push_back(r[i]);
  }
  sort(allpos.begin(), allpos.end());
  allpos.resize(unique(allpos.begin(), allpos.end()) - allpos.begin());
  diff.resize(allpos.size());
  unordered_map<ll, int> pos2id;
  for (int i = 0; i < allpos.size(); i++) pos2id[allpos[i]] = i, diff[i] = 0;
  for (int i = 0; i < n; i++) {
    int lid = pos2id[l[i]], rid = pos2id[r[i]];
    diff[lid + 1]++;
    diff[rid]--;
    // printf("add %d %d\n", lid, rid - 1);
  }

  typedef pair<ll, ll> pa;
  vector<pa> counts;

  counts.reserve(allpos.size());
  for (int i = 1; i < allpos.size(); i++) {
    ll left_end = allpos[i - 1];
    ll len = allpos[i] - left_end;
    counts.push_back(pa{diff[i - 1], len});
    // printf("diff[%d]: %d, len: %d\n", i - 1, diff[i - 1], len);

    diff[i] += diff[i - 1];
  }
  // counts.push_back(diff[0]);
  sort(counts.begin(), counts.end(), greater<pa>{});
  ll answer = 0;
  for (int i = 0; i < counts.size(); i++) {
    if (!c) break;
    ll this_num = min(c, counts[i].second);
    c -= this_num;
    answer += counts[i].first * this_num;
  }
  return answer + n;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
