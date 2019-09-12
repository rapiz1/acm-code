#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 5e4 + 10;
typedef long long ll;
int mu[N];
bool vis[N];
std::vector<int> pri;
ll calc(int n, int m) {
	ll ans = 0;
	if (n > m) std::swap(n, m);
	for (int i = 1, j; i <= n; i = j + 1) {
		j = std::min(n/(n/i), m/(m/i));
		ans += (ll)(n/i)*(m/i)*(mu[j] - mu[i - 1]);
	}
	return ans;
}
int main() {
	mu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!vis[i]) mu[i] = -1, pri.push_back(i);
		for (int j = 0; j < (int)pri.size(); j++) {
			if ((ll)i*pri[j] >= N) continue;
			int k = i*pri[j];
			vis[k] = 1;
			if (i%pri[j] == 0) {
				mu[k] = 0;
				break;
			}
			else mu[k] = -mu[i];
		}
		mu[i] += mu[i-1];
	} 
	int n; scanf("%d", &n);
	while (n--) {
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		a--,c--;
		a/=k, b/=k, c/=k, d/=k;
		printf("%lld\n", calc(b, d) + calc(a, c) - calc(a, d) - calc(b, c));
	}
}
