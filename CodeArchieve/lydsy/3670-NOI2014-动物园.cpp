#include <cstdio>
#include <cstring>
#define file(x) "zoo."#x
typedef long long ll;
const int L = 1e6 + 1;
const ll M = 1e9 + 7;
char s[L];
ll nxt[L], num[L];
ll solve() {
	int n = strlen(s + 1);
	ll res = 1;
	int p = 0, p2 = 0;
	num[1] = 1;
	for (int i = 2; i <= n; i++) {
		while (p && s[p + 1] != s[i]) p = nxt[p];
		if (s[p + 1] == s[i]) p++;
		nxt[i] = p;
		num[i] = num[p] + 1;
		while (p2 && s[p2  + 1] != s[i]) p2 = nxt[p2];
		if (s[p2 + 1] == s[i]) p2++;
		while (p2*2 > i) p2 = nxt[p2];
		res = (res*(num[p2] + 1))%M;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s + 1), printf("%lld\n", solve());
}
