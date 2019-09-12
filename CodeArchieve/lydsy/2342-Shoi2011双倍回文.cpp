#include <cstdio>
#include <algorithm>
#include <set>
const int N = 1e6 + 10;
int n, f[N], dd[N];
char ss[N], s[N];
std::set<int> st;
namespace set{
	int a[N];
	inline int lowbit(int x) {return x&-x;}
	inline void add(int p, int v) {
		for (;p<=n; p += lowbit(p)) a[p] += v;
	}
	inline int pre(int p) {
		if (p < 0) return 0;
		int ret = 0;
		for (;p;p -= lowbit(p)) ret += a[p];
		return ret;
	}
	inline int count(int x) {return pre(x) - pre(x - 1);}
	inline int upper_bound(int x) {
		int l = x + 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (pre(mid) - pre(x - 1)) r = mid;
			else l = mid + 1;
		}
		return l;
	}
}
bool cmp(int a, int b) {return a + f[a] < b + f[b];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%s", &n, ss + 1);
	for (int i = 1; i <= n; i++) s[2*i] = ss[i], s[2*i-1]='#';
	s[n = n*2 + 1] = '#';
	s[n + 1] = '$';
	for (int i = 1, p = 0, mx = 0; i <= n; i++) {
		if (mx > i) f[i] = std::min(f[p*2 - i], mx - i);
		for(;s[f[i] + i] == s[-f[i] + i]; f[i]++);
		if (i + f[i] > mx) mx = f[i] + i, p = i;
		dd[i] = i;
	}
	std::sort(dd + 1, dd + 1 + n, cmp);
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) if (s[i] == '#') {
		set::add(i, 1);
		while (j <= n && dd[j] + f[dd[j]] <= i) {
			if (s[dd[j]] == '#') {
				if (set::count(dd[j])) set::add(dd[j], -1);
			}
			j++;
		}
		int bd = std::max(i - f[i], i - (f[i] + 1)/2);
		int ub = set::upper_bound(bd);
		if (set::count(ub)) ans = std::max(ans, (i - ub)*2);
	}
	printf("%d\n", ans);
}
