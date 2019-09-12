#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K = 110, N = 20;
int n, k, a[N][K], m[N];
ll M;
vector<ll> ans;
inline bool fit(int x, int p) {
	return a[p][lower_bound(a[p] + 1, a[p] + 1 + a[p][0], x) - a[p]] == x;
}
void brute() {
	int idx = 1;
//	for (int i = 1; i <= n; i++) if (a[i][0]*1.0/m[i] < a[idx][0]*1.0/m[idx]) idx = i;
	for (int i = 1; i <= n; i++) if (a[i][0]*m[idx] < a[idx][0]*m[i]) idx = i;
	for (int i = 1; i <= n; i++) sort(a[i] + 1, a[i] + 1 + a[i][0]);
	for (ll j = 0, cnt = 0; cnt <= k; j++)
		for (int i = 1; i <= a[idx][0]; i++) {
			ll x = a[idx][i] + j*m[idx];
			if (!x) continue;
			bool af = 1;
			for (int p = 1; p <= n; p++) if (!fit(x%m[p], p)) {af = 0;break;}
//			for (int p = 1; p <= n; p++) if (!val[p].count(x%m[p])) {af = 0;break;}
			if (af) ans.push_back(x), cnt++;
		}
}
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1,y = 0;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
int sel[N];
ll crt() {
	ll nm = m[1], nr = sel[1];
	for (int i = 2; i <= n; i++) {
		ll x, y, d;
		exgcd(nm, m[i], d, x, y);
		if ((sel[i] - nr)%d) return 0;
		x = mod((sel[i] - nr)/d*x, m[i]/d);
		nr += x*nm;
		nm = nm/d*m[i];
		nr = mod(nr, nm);
	}
	return nr;
}
void dfs(int p) {
	if (p > n) {
		ans.push_back(crt());
		return;
	}
	for (int i = 1; i <= a[p][0]; i++) {
		sel[p] = a[p][i];
		dfs(p + 1);
	}
}
int main() {
	while (scanf("%d%d", &n, &k) == 2 && n) {
		memset(a, 0, sizeof a);
		long long est = 1;
		M = 1;
		int mxm = -1;
		ans.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", m + i, &a[i][0]);
			mxm = max(mxm, m[i]);
			est*=a[i][0];
			M *= m[i];
			for (int j = 1; j <= a[i][0]; j++) scanf("%d", &a[i][j]);
		}
		if (est > 1e4) brute();
		else dfs(1);
		sort(ans.begin(), ans.end());
		for (ll i = 0; k; i++) {
			for (int j = 0; j < ans.size(); j++) {
				ll x = i*M + ans[j];
				if (x) printf("%lld\n", x), k--;
				if (!k) break;
			}
		}
		putchar('\n');
	}
}
