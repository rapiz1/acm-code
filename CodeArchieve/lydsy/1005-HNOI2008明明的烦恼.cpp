#include <cstdio>
#include <cstring>
#include <vector>
const int N = 1010, BASE = 1e3, W = 1010;
int n, m, idx[N];
std::vector<int> pri;
bool vis[N];
struct Num {
	static const int L = 1000;
	int a[L], n;
	Num(int x = 0) {
		memset(this, 0, sizeof *this);
		for (;x;x/=BASE) a[++n] = x%BASE;
	}
	void show() {
		printf("%d", a[n]);
		for (int i = n - 1; i; i--) printf("%03d", a[i]);
	}
}ans(1);
void mul(Num& a, const Num& b) {
	Num c;
	c.n = a.n + b.n;
	for (int i = 1; i <= a.n; i++) for (int j = 1; j <= b.n; j++)
		c.a[i + j - 1] += a.a[i]*b.a[j];
	int g = 0;
	for (int i = 1; i <= c.n; i++) {
		g += c.a[i];
		c.a[i] = g%BASE;
		g /= BASE;
	}
	for (;c.n && !c.a[c.n]; c.n--);
	a = c;
}
inline void add(int n, int d) {
	for (int i = 0; i < (int)pri.size() && pri[i] <= n; i++) {
		for (int x = n; x; x/= pri[i]) idx[i] += x/pri[i]*d;
	}
}
int main() {
//	freopen("input", "r", stdin);
	for (int i = 2; i < N; i++) {
		if (!vis[i]) pri.push_back(i);
		for (int j = 0; j < (int)pri.size(); j++) {
			int k = i*pri[j];
			if (k >= N) break;
			vis[k] = 1;
			if (!i%pri[j]) break;
		}
	}
	scanf("%d", &n);
	int un = n - 2, m = 0;
	add(n - 2, 1);
	for (int i = 1; i <= n; i++) {
		int d; scanf("%d", &d);
		if (d == -1) m++;
		else if (d > 0) un -= d - 1, add(d - 1, -1);
		else {
			puts("0");
			return 0;
		}
	}
	if (un >= 0) add(un, -1);
	else {
		puts("0");
		return 0;
	}
	if (m) {
		add(m - 1, -un);
		add(m, un);
	}
	for (int i = 0; i < (int)pri.size(); i++) {
		Num tt(pri[i]);
		for (int j = 1; j <= idx[i]; j++) mul(ans, tt); 
	}
	ans.show();
}
