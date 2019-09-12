#include <cstdio>
#include <cstring>
#include <vector>
const int N = 21*2e5 + 10, C = 10;
int n, c, co[int(1e5 + 10)], du[int(1e5 + 10)];
std::vector<int> to[int(1e5 + 10)];
long long ans;
namespace SAM {
	int sz = 1, nxt[N][C], pre[N], val[N];
	int extend(int c, int last) {
		int np = ++sz, p = last;
		val[np] = val[p] + 1;
		for (;p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
		if (p) {
			int q = nxt[p][c];
			if (val[q] == val[p] + 1) pre[np] = q;
			else {
				int nq = ++sz;
				val[nq] = val[p] + 1, pre[nq] = pre[q];
				memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
				pre[q] = nq, pre[np] = nq;
				for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
			}
		}
		else pre[np] = 1;
		ans += val[np] - val[pre[np]];
		return np;
	}
}
namespace Trie{
	int sz = 1, nxt[N][C];
	void go(int u, int& p, int fa) {
		if (!p) p = ++sz;
		for (int i = 0; i < to[u].size(); i++) {
			int v = to[u][i], c = co[v];
			if (v == fa) continue;
			go(v, nxt[p][c], u);
		}
	}
	struct QNODE{int u, last;}q[N];
	void gen() {
		static int h, t;
		q[t++] = (QNODE){1, 1};
		while (h < t) {
			QNODE now = q[h++];
			int u = now.u, last = now.last;
			for (int i = 0; i < c; i++) 
				if (nxt[u][i]) q[t++] = (QNODE){nxt[u][i], SAM::extend(i, last)};
		}
	}
	int s[N];
}
int main() {
	freopen("zjoi15_substring.in", "r", stdin);
	freopen("zjoi15_substring.out", "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d", co + i);
	for (int i = 1; i < n; i++) {
		int u, v;scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
		du[u]++, du[v]++;
	}
	for (int i = 1; i <= n; i++) if (du[i] == 1) 
		Trie::go(i, Trie::nxt[1][co[i]], -1);
	Trie::gen();
	printf("%lld\n", ans);
}
