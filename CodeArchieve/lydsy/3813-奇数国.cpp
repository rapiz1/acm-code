#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long ll;
const int N = 1e5 + 10, P = 61, U = 400, M = 19961993;
namespace I {
	const int L = 1 << 15 | 1;
	char buf[L], *s, *t;
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
struct BIT{
	int a[N];
	int lowbit(int x) {return x&-x;}
	void add(int p, int v) {if (v) for(;p<N;p+=lowbit(p)) a[p]+=v;}
	int pre(int p) {
		int r = 0;
		for (;p;p-=lowbit(p)) r += a[p];
		return r;
	}
	int sum(int l, int r) {return pre(r) - pre(l - 1);}
}bit[P];
int n, pri[P], num;
bool ip[U];
int qpow(int x, int r) {
	r%=M - 1;
	if (!x) return 0;
	int ret = 1;
	for (x%=M; r;r>>=1, x=(ll)x*x%M) if (r&1) ret = (ll)ret*x%M;
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	memset(ip, 1, sizeof ip);
	for (int i = 2; i < U; i++) if (ip[i]){
		pri[++num] = i;
		for (int j = i + i; j < U; j += i) ip[j] = 0;
	}
	num = 60;
	for (int i = 1; i <= int(1e5); i++) bit[2].add(i, 1);
	n = gi();
	while (n--) {
		int a, b, c;
		a = gi(), b = gi(), c = gi();
		if (a) {
			for (int i = 1; i <= num; i++) bit[i].add(b, -bit[i].sum(b, b));
			for (int i = 1, x = c; i <= num && x; i++) if (x%pri[i] == 0) {
				int cc = 0;
				while (x%pri[i] == 0) x/=pri[i], cc++;
				bit[i].add(b, cc);
			}
		}
		else {
			int ret = 1;
			for (int i = 1; i <= num; i++) {
				int cc = bit[i].sum(b, c);
				if (cc)
				ret = (ll)ret*qpow(pri[i],cc - 1)%M*(pri[i] - 1)%M;
			}
			printf("%d\n", ret);
		}
	}
}
