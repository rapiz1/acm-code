#include <cstdio>
#include <algorithm>
const int M = 3e5 + 10;
int n, m, a[M], as[M], b[M];
struct L{int l, r;
	inline int len()const {return r - l + 1;}
	bool operator<(const L& b)const {return len() < b.len();}
}st[M];
inline int lowbit(int x){ return x&-x;}
inline void add(int p, int v) {
	while (p < M) a[p] += v, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += a[p], p -= lowbit(p);
	return s;
}
inline void modi(int l, int r) {
	add(l, 1), add(r + 1, -1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &st[i].l, &st[i].r);
	std::sort(st + 1, st + 1 + n);
	for (int i = 1; i <= n; i++) b[0]++, b[st[i].len() + 1]--;
	for (int i = 1, p = 1; i <= m; i++) {
		while (p <= n && st[p].len() < i) modi(st[p].l, st[p].r), p++;	
		for (int j = i; j <= m; j += i) as[i] += pre(j);
	}
	for (int i = 1; i <= m; i++) {
		b[i] += b[i - 1];
		printf("%d\n", as[i] + b[i]);
	}
}
