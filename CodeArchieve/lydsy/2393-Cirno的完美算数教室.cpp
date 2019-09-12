#include <cstdio>
#include <algorithm>
typedef long long ll;
const int NUM = 1 << 11;
int num;
ll a[NUM], l, r;
ll gcd(ll a, ll b) {return b?gcd(b,a%b) : a;}
inline ll lcm(ll a, ll b) {return a*b/gcd(a, b);}
void gen(ll now) {
	if (now > r) return;
	a[num++] = now;
	gen(now*10 + 9), gen(now*10 + 2);
}
namespace solver{
	ll n, ans;
	int cnt;
	void dfs(ll lcc, int p) {
		if (lcc > n) return;
		if (p > num) {
			ans += ((cnt&1)?1:-1)*n/lcc;
			return;
		}
		cnt++, dfs(lcm(lcc, a[p]), p + 1), cnt--;
		dfs(lcc, p + 1);
	}
	ll calc(ll _n) {
		ans = 0;
		n = _n;
		dfs(1, 1);
		return ans + n;
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%lld%lld", &l, &r);
	gen(0);
	num--;
	{
		std::sort(a + 1, a + 1 + num);
		int tmp = 0;
		static ll b[NUM];
		static bool rm[NUM];
		for (int i = 1; i <= num; i++) if (!rm[i]) {
			b[++tmp] = a[i];
			for (int j = i + 1; j <= num; j++) 
				if (a[j]%a[i] == 0) rm[j] = 1;
		}
		num = tmp;
		for (int i = 1; i <= num; i++) a[i] = b[i];//, printf("%lld ", a[i]);
	//	printf("\n%d\n", tmp);
	}
	printf("%lld", solver::calc(r) - solver::calc(l - 1));
}
