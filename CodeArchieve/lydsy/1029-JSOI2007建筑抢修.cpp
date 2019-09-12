#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
const int N = 150010;
typedef std::pair<int, int> pa;
int n;
pa a[N];
struct CMP {
	bool operator()(const pa& a, const pa& b) {return a.second < b.second;}
};
std::priority_queue<pa, std::vector<pa>, CMP> q;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].second, &a[i].first);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1, l = 0; i <= n; i++) {
		l += a[i].first - a[i - 1].first;
		if (l >= a[i].second) l -= a[i].second, q.push(a[i]);
		else {
			if (!q.empty() && a[i].second < q.top().second) {
				pa x = q.top();q.pop();
				l += x.second;
				q.push(a[i]);
				l -= a[i].second;
			}
		}
	}
	printf("%d\n", (int)q.size());
}
