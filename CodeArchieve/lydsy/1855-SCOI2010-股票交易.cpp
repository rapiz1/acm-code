#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
const int N = 2010;
int n, w, p, as[N], bs[N], ap[N], bp[N], f[N][N], head, tail, q[N];
inline int buy(int yes, int hv, int tod, int now) {
	return f[yes][hv] - (now - hv)*ap[tod];
}
inline int sell(int yes, int hv, int tod, int now) {
	return f[yes][hv] + (hv - now)*bp[tod];
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &p, &w);
	for (int i = 1; i <= n; i++) scanf("%d%d%d%d", ap + i, bp + i, as + i, bs + i);
	memset(f, 0xc0, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= p; j++) f[i][j] = f[i - 1][j];
		head = tail = 0;
		for (int j = 1; j <= p; j++) {
			while (head != tail && q[head] < j - as[i]) head++;
			while (head != tail && buy(max(i - w - 1, 0), q[tail - 1], i, j) < buy(max(i - w - 1, 0), j - 1, i, j)) tail--;
			q[tail++] = j - 1;
			f[i][j] = max(f[i][j], buy(max(i - w - 1, 0), q[head], i, j));
		}
		head = tail = 0;
		for (int j = p - 1; j >= 0; j--) {
			while (head != tail && q[head] > j + bs[i]) head++;
			while (head != tail && sell(max(i - w - 1, 0), q[tail - 1], i, j) < sell(max(i - w - 1, 0), j + 1, i, j)) tail--;
			q[tail++] = j + 1;
			f[i][j] = max(f[i][j], sell(max(i - w - 1, 0), q[head], i, j));
		}
	}
	printf("%d\n", f[n][0]);
}
