/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 12:26:52 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
const int N = 2050;
int k;
struct Win {
  vector<string > buf;
  Win(int k=1) {
    int n = 1<<k;
    buf.resize(n);
    if (k == 1) {
      buf[0] = "CC";
      buf[1] = "PC";
    }
  }
  void print() {
    for (auto& x: buf) {
      printf("%s\n", x.c_str());
    }
  }
}all[11];
void init() {
//  all[1].print();
  for (int i = 2; i <= 10; i++) {
    all[i] = Win(i);
    int len  = 1<<i;
    for (int j = 0; j < len/2; j++) {
      all[i].buf[j] += all[i-1].buf[j];
      all[i].buf[j] += all[i-1].buf[j];
    }
    for (int j = len/2; j < len; j++) {
      for (int k = 0; k < len/2; k++) {
        char ch;
        if (all[i-1].buf[j-len/2][k] == 'P') ch = 'C';
        else ch = 'P';
        all[i].buf[j] += ch;
      }
      for (int k = len/2; k < len; k++) {
        all[i].buf[j] += all[i-1].buf[j-len/2][k-len/2];
      }
    }
    //printf("#%d\n", i);
//    all[i].print();
  }
}
int main() {
  init();
  int ks; scanf("%d", &ks);
  while (ks--) {
    scanf("%d", &k);
    all[k].print();
  }
}

