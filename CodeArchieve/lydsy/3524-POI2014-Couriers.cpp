#include <cstdio>
#include <cstring>
const int N = 5e5 + 10, NL = N*20;
int n, m, rt[N], sz, ch[NL][2], s[NL], q1;
void change(int& o, int p, int l, int r) {
	o = ++sz;
	if (l == r) {
		s[o] = s[p] + 1;
		return;
	}
	memcpy(ch[o], ch[p], sizeof(ch[p]));
	int mid = l + r >> 1;
	if (q1 <= mid) change(ch[o][0], ch[p][0], l, mid);
	else change(ch[o][1], ch[p][1], mid + 1, r);
	s[o] = s[ch[o][0]] + s[ch[o][1]];
}
int query(int l, int r) {
	int d = (r - l + 1) >> 1, o = rt[l - 1], p = rt[r];
	l = 1, r = n;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (s[ch[p][0]] - s[ch[o][0]] > d) o = ch[o][0], p = ch[p][0], r = mid;
		else o = ch[o][1], p = ch[p][1], l = mid + 1;
	}
	return s[p] - s[o] > d ? l : 0;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &q1);
		change(rt[i], rt[i - 1], 1, n);
	}
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}
