#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r, c, k;
ll r1, r2, c1, c2;
void input() {
  cin >> r >> c >> k;
  cin >> r1 >> c1 >> r2 >> c2;
}
ll min_cuts_line(ll l) { return (l + k - 1) / k; }
ll solve() {
  ll answer = LONG_LONG_MAX;

  // convert to grid points
  r1--, c1--;

  ll left_top_y = r1;
  ll left_top_x = c1;
  ll right_top_y = r1;
  ll right_top_x = c2;
  ll top_min_len = min(c - c1, c2);

  ll width = c2 - c1;
  ll height = r2 - r1;

  {
    ll answer1 = 0;
    if (r1 != 0) answer1 += min_cuts_line(top_min_len);
    if (c2 != c) answer1 += min_cuts_line(height);
    if (r2 != r) answer1 += min_cuts_line(width);
    if (c1 != 0) answer1 += min_cuts_line(height);
    answer = min(answer, answer1);
  }
  {
    ll answer1 = 0;
    if (r1 != 0) answer1 += min_cuts_line(width);
    if (c2 != c) answer1 += min_cuts_line(height);
    if (r2 != r) answer1 += min_cuts_line(top_min_len);
    if (c1 != 0) answer1 += min_cuts_line(height);
    answer = min(answer, answer1);
  }

  ll left_min_len = min(r - r1, r2);
  {
    ll answer1 = 0;
    if (r1 != 0) answer1 += min_cuts_line(width);
    if (c2 != c) answer1 += min_cuts_line(left_min_len);
    if (r2 != r) answer1 += min_cuts_line(width);
    if (c1 != 0) answer1 += min_cuts_line(height);
    answer = min(answer, answer1);
  }
  {
    ll answer1 = 0;
    if (r1 != 0) answer1 += min_cuts_line(width);
    if (c2 != c) answer1 += min_cuts_line(height);
    if (r2 != r) answer1 += min_cuts_line(width);
    if (c1 != 0) answer1 += min_cuts_line(left_min_len);
    answer = min(answer, answer1);
  }

  ll more = LONG_LONG_MAX;
  {
    ll inner = 0;
    inner += (width - 1) * min_cuts_line(height);
    inner += width * (height - 1);
    more = min(more, inner);
  }
  {
    ll inner = 0;
    inner += (height - 1) * min_cuts_line(width);
    inner += height * (width - 1);
    more = min(more, inner);
  }

  answer += more;

  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %lld\n", i, solve());
  }
}
