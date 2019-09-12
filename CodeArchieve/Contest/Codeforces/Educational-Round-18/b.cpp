#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, nxt[N], pre[N], k, a[N];
int main() {
//	freopen("input", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	for (int i = 1; i < n; i++) nxt[i] = i + 1, pre[i + 1] = i;
	nxt[n] = 1, pre[1] = n;
	for (int i = 1, p = 1; i <= k; i++) {
		a[i] %= n - i + 1;
		for (int j = 1; j <= a[i]; j++) p = nxt[p];
		cout << p << " ";
		nxt[pre[p]] = nxt[p], pre[nxt[p]] = pre[p];
		p = nxt[p];
	}
}
