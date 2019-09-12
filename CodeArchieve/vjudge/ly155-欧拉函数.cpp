#include <cstdio>
#include <cctype>
typedef long long ll;
namespace I {
	const int L = 1 << 15 | 1;
	char buf[L], *s, *t;
	inline int gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		if (s == t) return EOF;
		return *s++;
	}
	inline int gi() {
		int ch = gc(), r = 0;
		while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
		return r;
	}
}using I::gi;
const int N = 3e6 + 10;
int phi[N], pri[N], sz;
bool vis[N];
int main() {
//	freopen("input", "r", stdin);
	phi[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!vis[i]) phi[i] = i - 1, vis[i] = 1, pri[sz++] = i;
		for (int j = 0; j < sz; j++) {
			ll k = (ll)pri[j]*i;
			if (k > N) break;
			vis[k] = 1;
			if (i%pri[j]==0) {
				phi[k] = phi[i]*pri[j];
				break;
			}
			else phi[k] = phi[i]*(pri[j] - 1);
		}
	}
	for (int n;(n = gi());printf("%d\n", phi[n]));
}
