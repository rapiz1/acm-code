#include <cstdio>
#include <algorithm>
typedef long long ll;
const int NUM = 1 << 12;
int num;
ll l, r, a[NUM];
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
inline ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
void gen(ll now) {
	if (now > r) return;
	a[num++] = now;	
	gen(now*10 + 6), gen(now*10 + 8);
}
int cnt;
ll ans;
void dfs(ll lcc, int p) {
	if (lcc > r || lcc <= 0) return;
	if (p > num) {
		if (cnt) ans += (cnt&1?1:-1)*(r/lcc - l/lcc);
		return;
	}
	cnt++, dfs(lcm(lcc, a[p]), p + 1), cnt--;
	dfs(lcc, p + 1);
}
bool cmp(ll x, ll y) {return x > y;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%lld%lld", &l, &r);
	l--;
	gen(0);
	num--;
	std::sort(a + 1, a + 1 + num);
	{
		static ll b[NUM];
		static bool rm[NUM];
		int tmp = 0;
		for (int i = 1; i <= num; i++) if (!rm[i]) {
			b[++tmp] = a[i];
			for (int j = i + 1; j <= num; j++) if (a[j]%a[i] == 0) rm[j] = 1;
		}
		num = tmp;
		for (int i = 1; i <= num; i++) a[i] = b[i];
	}
	std::sort(a + 1, a + 1 + num, cmp);
	dfs(1, 1);
	printf("%lld\n", ans);
}
