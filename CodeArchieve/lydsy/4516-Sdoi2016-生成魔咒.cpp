#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
const int N = 2e6;
int pre[N], sz = 1, last = 1, val[N];
long long ans;
std::map<int, int> nxt[N];
inline void extend(int c) {
	int p = last, np = ++sz;
	val[np] = val[p] + 1;
	for (;p&&!nxt[p].count(c); p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q;
		else {
			int nq = ++sz;
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			nxt[nq] = nxt[q];
			pre[q] = nq, pre[np] = nq;
			for(;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last = np;
	ans += val[np] - val[pre[np]];
	printf("%lld\n", ans);
}
int main() {
//	freopen("input", "r", stdin);
	int n;scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), extend(x);
}
