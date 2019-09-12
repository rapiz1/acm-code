#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5 + 10, V = 6e6, K = 32;
typedef long long ll;
int n, m, top, ch[V][2], rt[N], a[N], s[N][K][2];
ll inc[V], la, val[V];
void add(int& o, int p, int l, int r, int q1, int q2, int q3) {
	o = ++top;
	memcpy(ch[o], ch[p], sizeof ch[0]);
	inc[o] = inc[p];
	val[o] = val[p];
	if (q1 <= l && r <= q2) {
		inc[o] += q3;
		val[o] += q3*(r - l + 1ll);
		return;
	}
	int mid = (l+r)>>1;
	if (q1 <= mid) add(ch[o][0], ch[p][0], l, mid, q1, q2, q3);
	if (mid < q2) add(ch[o][1], ch[p][1], mid+1, r, q1, q2, q3);
	val[o] += (std::min(q2, r) - std::max(l, q1) + 1ll)*q3;
}
ll query(int o, int l, int r, int q1, int q2, ll nin) {
	if  (q1 <= l && r <= q2) return (r - l + 1)*nin + val[o];
	nin+=inc[o];
	ll ret = 0;
	int mid = (l+r)>>1;
	if (q1<=mid) ret+=query(ch[o][0], l, mid, q1, q2, nin);
	if (mid<q2) ret+=query(ch[o][1],mid+1, r, q1, q2, nin);
	return ret;
}
int main() {
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		int j;
		for(j=K-1;~j;j--) if (a[i]>>j&1) break;
		a[i]^=a[i-1];
		if (j>=0) s[i][j][a[i]>>j&1]++;
		for (int k = 0; k < K; k++) for (int d = 0; d < 2; d++) s[i][k][d] += s[i-1][k][d];
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while  (l < r) {
			int mid = (l + r+1) >> 1;
			bool flag = 1;
			for (int k = 0; k < K; k++) {
				int d = a[i-1]>>k&1;
				if (s[mid][k][d] - s[i-1][k][d]) {flag=0;break;}
			}
			if (flag) l = mid;
			else r = mid - 1;
		}
		add(rt[i], rt[i-1], 1, n, i, l, 1);
	}
	scanf("%d", &m);
	for (int a, b; m--;) {
		scanf("%d%d", &a, &b);
		a=(a+la)%n+1, b=(b+la)%n+1;
		if (a > b) std::swap(a, b);
		printf("%lld\n", la = query(rt[b], 1, n, a, b, 0) - query(rt[a-1], 1, n, a, b, 0));
	}
}
