#include <cstdio>
#define file(x) "shuliec."#x
typedef long long ll;
const int N = 100010;
int n, m;
ll a[N], b[N];
inline int lowbit(int x){return x&-x;}
void add(int idx, ll v) {
	for (int p = idx;p<=n;p+=lowbit(p)) a[p] += v, b[p] += v*idx;
}
ll pre(int idx) {
	ll ret = 0;
	for (int p = idx;p;p-=lowbit(p)) ret += (idx + 1ll)*a[p] - b[p];
	return ret;
}
char cmd[5];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	ll x;
	for (int i = 1; i <= n; i++) scanf("%lld", &x), add(i, x), add(i + 1, -x);
	scanf("%d", &m);
	while (m--) {
		int l, r;
		scanf("%s%d%d", cmd, &l, &r);
		if (cmd[0] == 'A') {
			ll x;
			scanf("%lld", &x);
			add(l, x);
			add(r + 1, -x);
		}
		else printf("%lld\n", pre(r) - pre(l - 1));
	}
}
