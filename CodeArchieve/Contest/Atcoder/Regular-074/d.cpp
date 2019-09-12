#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 3e5 + 10;
typedef long long ll;
int n, a[N];
ll ans = -1e18, pre[N], suf[N];
std::priority_queue<int> q;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= 3*n; i++) scanf("%d", a + i);
	for (int i = 1; i <= 3*n; i++) {
		pre[i] = pre[i - 1] + a[i];
		q.push(-a[i]);
		if (q.size() > n) {
			int x = -q.top();
			q.pop();
			pre[i] -= x;
		}
	}
	while (!q.empty()) q.pop();
	for (int i = 3*n; i; i--) {
		suf[i] = suf[i + 1] + a[i];
		q.push(a[i]);
		if (q.size() > n) {
			int x = q.top();
			q.pop();
			suf[i] -= x;
		}
	}
	for (int i = n; i <= 2*n; i++) 
		ans = std::max(ans, pre[i] - suf[i + 1]);
	printf("%lld\n", ans);
}
