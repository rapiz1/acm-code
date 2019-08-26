/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 26 Aug 2019 10:36:41 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 1010;
const int b[10][10] = {
{8,9,1,13},
{3,12,7,5},
{0,2,4,11},
{6,10,15,14}
};
int n, a[N][N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <n; j++) {
      int ik = i/4;
      int jk = j/4;
      a[i][j] = b[i%4][j%4] + (ik*(n/4)+jk)*16;
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

