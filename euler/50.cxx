#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int UP = 1e6, MAXN = 1010;

bool is_prime[UP];
vector<int> primes;

void make_prime() {
  memset(is_prime, 1, sizeof is_prime);
  for (int i = 2; i < UP; i++) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (int j = i + i; j < UP; j += i) is_prime[j] = 0;
  }
}

int main() {
  make_prime();
  assert(primes.size() >= MAXN);
  int maxl = 1, answer = 2;
  for (int i = 0; i < MAXN; i++) {
    int sum = 0;
    for (int j = i; j < MAXN && sum < UP; j++) {
      sum += primes[j];
      if (sum > UP) break;
      int l = j - i + 1;
      if (is_prime[sum] && l > maxl) {
        answer = sum;
        maxl = l;
      }
    }
  }
  cout << answer;
}
