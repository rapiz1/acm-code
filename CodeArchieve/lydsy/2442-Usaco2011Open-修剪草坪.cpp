#include <cstdio>
#include <algorithm>
#define file(x) "mowlawn." #x
typedef long long ll;
using std::max;
const int N = 1e5 + 10;
int n, k, head, tail;
ll f[N], a[N], ans;
struct D{int i;ll v;}q[N];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
	q[tail++] = (D){-1, 0};//考虑清楚怎么样才不会漏决策！这个决策代表选一个前缀
	for (int i = 1; i <= n; i++) {
		while (head != tail && i - q[head].i - 1 > k) head++; 
		while (head != tail && q[tail - 1].v < f[i - 1] - a[i]) tail--;
		q[tail++] = (D){i - 1, f[i - 1] - a[i]};
		f[i] = q[head].v + a[i];
		ans = max(ans, f[i]);
	}
	printf("%lld", ans);
}
