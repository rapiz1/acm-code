#include <cstdio>
#include <cassert>
#include <queue>
#include <algorithm>
const int N = 5e5 + 10, K = 20;
typedef long long ll;
int n, s[K][N], p[K][N], k, l, r;
ll ans;
inline int query(int l, int r) {
	int n = r - l + 1, k = 0;
	while (1<<(k+1) <= n) k++; 
	return std::min(s[k][l], s[k][r-(1<<k)+1]);
}
inline int findmn(int l, int r) {
	int n = r - l + 1, k = 0;
	while (1<<(k+1) <= n) k++; 
	return s[k][l] < s[k][r-(1<<k)+1] ? p[k][l] : p[k][r-(1<<k)+1];
}
struct Rhy {
	int i, l, r;
	inline int val()const {
		return s[0][i] - query(l, r);
	}
	bool operator<(const Rhy& rhs)const {
		return val() < rhs.val();
	}
};
std::priority_queue<Rhy> q;
int main() {
	scanf("%d%d%d%d", &n, &k, &l, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &s[0][i]), s[0][i] += s[0][i-1], p[0][i]=i;
	for (int k = 1; k < K; k++) for (int i = 0; i + (1<<k) -1 <= n; i++) {
		s[k][i] = std::min(s[k-1][i], s[k-1][i + (1<<(k-1))]);
		p[k][i] = s[k-1][i] < s[k-1][i + (1<<(k-1))] ? p[k-1][i] : p[k-1][i + (1<<(k-1))];
	}
	for (int i = l; i <= n; i++) q.push((Rhy){i, std::max(i - r, 0), i - l});
	while (k--) {
		Rhy x = q.top(); q.pop();
		ans += x.val();
		int pos = findmn(x.l, x.r);
		if (pos-1>=x.l) q.push((Rhy){x.i, x.l, pos - 1});
		if (pos+1<=x.r) q.push((Rhy){x.i, pos +1, x.r});
	}
	printf("%lld\n", ans);
}
