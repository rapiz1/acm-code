#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
typedef long long ll;
const int P = 1e5 + 10, S = 1e4;
int mu[P], prime[S], cnt, p;
bool vis[P];
ll h[P];
std::vector<ll> f[P];
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
inline void mkmu() {  
    memset(vis,0,sizeof vis);  
    mu[1] = 1;  
    cnt = 0;  
    for(int i=2; i<P; i++) {  
        if(!vis[i]) {  
            prime[cnt++] = i;  
            mu[i] = -1;  
        }  
        for(int j=0; j<cnt&&(ll)i*prime[j]<P; j++) {  
            vis[i*prime[j]] = 1;  
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];  
            else  
            {  
                mu[i*prime[j]] = 0;  
                break;  
            }  
        }  
    }
}  
struct Num {
	static const int L = 70;
	int a[L], sz;
	Num(ll x = 0, int p = 10) {
		sz = 0;
		while (x) a[++sz] = x%p, x/=p;
	}
}a, b;
ll calc(Num& x) {
	if (!x.sz) return 0;
	ll ret = 0;
	for (int i = 1; i < x.a[x.sz]; i++) ret += f[x.sz][i];
	for (int i = x.sz - 1; i; i--) {
		for (int j = 1; j < x.a[i]; j++) if (gcd(j, x.a[i + 1]) == 1) ret += f[i][j];
		if (!x.a[i] || gcd(x.a[i], x.a[i + 1]) != 1) break;
	}
	for (int i = 1; i < x.sz; i++) for (int j = 1; j < p; j++) ret += f[i][j];
	return ret;
}
void solve() {
	ll l, r;
	scanf("%lld%lld%d", &l, &r, &p);
	a = Num(l, p), b = Num(r + 1, p);
	int tot = std::max(a.sz, b.sz);
	for (int i = 1; i <= tot; i++) f[i].clear(), f[i].resize(p);
	for (int i = 1; i < p; i++) f[1][i] = 1;
	for (int i = 2; i <= tot; i++) {
		for (int j = 1; j < p; j++) {
			h[j] = 0;
			for (int k = j; k < p; k += j) h[j] += f[i - 1][k];
			h[j] *= mu[j];
			for (int k = j; k < p; k += j) f[i][k] += h[j];
		}
	}
	printf("%lld\n", calc(b) - calc(a));
}
int main() {
	mkmu();
	int t; scanf("%d", &t);
	while (t--) solve();
}
