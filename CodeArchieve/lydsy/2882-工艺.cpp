#include <cstdio>
#include <map>
const int N = 2e6 + 10;
int sz = 1, last = 1, pre[N], val[N], n, s[N]; 
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
			pre[np] = nq, pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1;
	last =  np;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", s + i), extend(s[i]);
	for (int i = 1; i <= n; i++) extend(s[i]);
	for (int i = 1, p = 1; i <= n; i++) {
		std::map<int, int>::iterator it = nxt[p].begin();
		printf("%d%c", it->first, " \n"[i == n]);
		p = it->second;
	}
}
