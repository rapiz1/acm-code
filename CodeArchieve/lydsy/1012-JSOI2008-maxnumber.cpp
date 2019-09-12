#include <cstdio>
const int N = 2e5 + 10;
typedef long long ll;
struct PA{ll i, v;}a[N];
int m, sz, tot;
ll d;
char cmd[2];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%lld", &m, &d);
	ll t = 0;
	while (m--) {
		ll x;
		scanf("%s%lld", cmd, &x);
		if (cmd[0] == 'Q') {
			x = tot - x + 1; 
			int l = 1, r = sz, mid;
			while (l < r) {
				mid = l + r >> 1;
				if (a[mid].i >= x) r = mid;
				else l = mid + 1;
			}
			printf("%lld\n", t = a[l].v);
		}
		else if (cmd[0] == 'A') {
			++tot;
			ll c = (x + t)%d;
			while (sz && a[sz].v <= c) --sz;
			a[++sz] = (PA){tot, c};
		}
	}
}
