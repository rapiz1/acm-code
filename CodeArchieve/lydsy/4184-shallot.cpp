#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define lch (o<<1)
#define rch ((o<<1)|1)
#define mid ((l + r) >> 1)
typedef unsigned int uint;
const int N = int(5e5 + 10) << 2;
int n;
struct BASE{
	std::vector<uint> r;
	BASE() {r.resize(32, 0);}
	void ins(uint x) {
		for (int i = 31; ~i; i--) if (x>>i&1) {
			if (r[i]) x ^= r[i];
			else {r[i] = x;break;}
		}
	}
	uint val()const {
		uint ret = 0;
		for (int i = 31; ~i; i--) ret = std::max(ret, ret^r[i]);
		return ret;
	}
};
std::vector<int> val[N];
std::map<int, int> hv;
void change(int o, int l, int r, int q1, int q2, uint x) {
	if (q1 <= l && r <= q2) val[o].push_back(x);
	else {
		if (q1 <= mid) change(lch, l, mid, q1, q2, x);
		if (mid < q2) change(rch, mid + 1, r, q1, q2, x);
	}
}
void dfs(int o, int l, int r, BASE bas) {
	for (int i = 0; i < val[o].size(); i++) bas.ins(val[o][i]);
	if (l == r) printf("%u\n", bas.val());
	else dfs(lch, l, mid, bas), dfs(rch, mid + 1, r, bas);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (x > 0) if (!hv[x]) hv[x] = i;else;
		else {
			x = -x;
			if (hv[x]) {
				change(1, 1, n, hv[x], i - 1, x);
				hv[x] = 0;
			}
		}
	}
	for (std::map<int, int>::iterator it = hv.begin(); it != hv.end(); it++)
		if (it->second) change(1, 1, n, it->second, n, it->first);
	dfs(1, 1, n, BASE());
}
