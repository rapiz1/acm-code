#include <cstdio>
#include <map>
#include <vector>
const int V = 2e5 + 10, L = 4010, N = 5e4 + 10, M = 1e5 + 10;
int n, m, sz, q[V], h, t, fail[V], cnt[V], ans[N], end[V];
bool in[V];
typedef std::vector<int> str;
typedef std::map<int, int>::iterator IT;
std::map<int, int> ch[V];
str name[N], dian[M];
inline void rd(str& vec) {
	int l, x;scanf("%d", &l);
	while (l--) scanf("%d", &x), vec.push_back(x);
}
inline int get(const str& s) {
	int i, now;
	for (i = 0, now = 0; i < (int)s.size(); i++) {
		if (!ch[now].count(s[i])) ch[now][s[i]] = ++sz;
		now = ch[now][s[i]];
	}
	end[now]++;
	return now;
}
inline void match(const str& s, int id) {
	h = t = 0;
	for (int i = 0, p = 0; i < (int)s.size(); i++) {
		while (p && !ch[p].count(s[i])) p = fail[p];
		p = ch[p][s[i]];
		for (int x = p; x; x = fail[x]) if (!in[x]) {
			in[x] = 1;
			cnt[x]++;
			ans[id] += end[x];
			q[t++] = x;
		}
	}
	while (t) in[q[--t]] = 0;
}
int main() {
//	freopen("wtfname.in", "r", stdin);
//	freopen("wtfname.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) rd(name[i]), name[i].push_back(1e9), rd(name[i]);
	for (int i = 1; i <= m; i++) rd(dian[i]), get(dian[i]);
	for (IT it = ch[0].begin(); it != ch[0].end(); it++) q[t++] = it->second;
	while (h < t) {
		int x = q[h++];
		for (IT it = ch[x].begin(); it != ch[x].end(); it++) {
			q[t++] = it->second;
			int p = fail[x];
			while (p && !ch[p].count(it->first)) p = fail[p];
			fail[it->second] =  ch[p][it->first];
		}
	}
	for (int i = 1; i <= n; i++) match(name[i], i);
	for (int i = 1; i <= m; i++) printf("%d\n", cnt[get(dian[i])]);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
