#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>
const int N = 2e5 + 10;
int f[N], n, lef[N], rig[N];
char ss[N], s[N];
std::set<int> st;
std::vector<int> del[N];
int main() {
	scanf("%s", ss + 1);
	for (int i = 1; ss[i]; i++) s[2*i] = ss[i];
	n = strlen(ss + 1)*2 + 1;
	s[n + 1] = '$';
	for (int i = 1; i <= n; i++) if (!s[i]) s[i] = '#';
	for (int i = 1, mx = 0, p = 0; i <= n; i++) {
		if (mx > i) f[i] = std::min(f[p*2 - i], mx - i);
		for (;s[i + f[i]] == s[i - f[i]]; f[i]++);
		if (i + f[i] > mx) mx = i + f[i], p = i;
	}
	for (int i = 1; i <= n; i++) {
		del[f[i] + i].push_back(i);
		for (int j = 0; j < del[i].size(); j++) st.erase(st.find(del[i][j]));
		del[i].clear();
		st.insert(i);
		rig[i] = i - *st.begin();
	}
	for (int i = n; i; i--) {
		del[i - f[i]].push_back(i);
		for (int j = 0; j < del[i].size(); j++) st.erase(st.find(del[i][j]));
		del[i].clear();
		st.insert(i);
		lef[i] = *st.rbegin() - i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = std::max(ans, rig[i] + lef[i]);
	printf("%d\n", ans);
}
