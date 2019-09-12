#include <cstdio>
#include <cctype>
#include <cstring>
#define file(x) "sorttest."#x
const int N = 2000010, mask = (1 << 16) - 1;
namespace I {
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int ch = gc(), r = 0;
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
		return r;
	}
}using I::gi;
int n, a[N], b[N], cnt[mask + 1];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	n = gi();
	for (int i = 1; i <= n; i++) cnt[(a[i] = gi())&mask]++;
	for (int i = 1; i <= mask; i++) cnt[i] += cnt[i - 1];
	for (int i = n; i; i--) b[cnt[a[i]&mask]--] = a[i];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) cnt[b[i]>>16]++;
	for (int i = 1; i <= mask; i++) cnt[i] += cnt[i - 1];
	for (int i = n; i; i--) a[cnt[b[i]>>16]--] = b[i];
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
