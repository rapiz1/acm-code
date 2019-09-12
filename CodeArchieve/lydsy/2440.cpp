#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
const int N =  1e5;
int mu[N];
bool vis[N];
std::vector<int> pri;
void init() {
	mu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!vis[i]) pri.push_back(i), mu[i] = -1;
		for (int j = 0; j < (int)pri.size(); j++) {
			if ((long long)i*pri[j] >= N) break;
			int k = i*pri[j];
			vis[k] = 1;
			if (i%pri[j]) mu[k] = -mu[i];
			else {mu[k]=0;break;}
		}
		mu[i] += mu[i-1];
	}
}
inline int calc(int n) {
	int sq = sqrt(n)+1e-8, ret=0;
	for (int i = 1 , j; i <= sq; i=j+1) {
		j = sqrt(n/(n/(i*i))) + 1e-8;
		j = std::min(j, sq);
		ret += n/(i*i)*(mu[j] - mu[i-1]);
	}
	return ret;
}
void solve() {
	int k;scanf("%d", &k);
	int l = 0, r = 2*k;
	while (l < r) {
		int mid = ((long long)l+r)>>1;
		if (calc(mid) >= k) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
int main() {
	init();
	int t; scanf("%d", &t);
	while (t--) solve();
}
