#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n, m, p[N];
ll ans, du[N], zi[N], cnt;
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v; 
		scanf("%d%d", &u, &v);
		if (u != v) du[u]++, du[v]++, p[find(u)] = find(v);
		else zi[u]++, cnt++;
	}
	{
		int base = 1;
		for (;base <= n && !(du[base] || zi[base]); base++);
		if (base > n) {
			puts("0");
			return 0;
		}
		for (int i = 1; i <= n; i++) if ((du[i] || zi[i]) && find(i) != find(base)) {
			puts("0");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) ans += du[i]*(du[i] - 1)/2;
	ans += cnt*(m - cnt) + cnt*(cnt - 1)/2;
	cout << ans;
}
