#include <cstdio>
#define file "network1."
typedef long long ll;
const int N = 200;
struct Data{ll dis, cnt;
	Data(ll a=1e17, ll b=0):dis(a), cnt(b) {;}
	Data operator+(const Data& rhs)const {
		if (dis < rhs.dis) return *this;
		else if (dis > rhs.dis) return rhs;
		else return Data(dis, cnt + rhs.cnt);
	}
	Data operator*(const Data& rhs)const {
		return Data(dis + rhs.dis, cnt*rhs.cnt);
	}
}f[N][N];
double ans[N];
int n, m;
int main() {
//	freopen(file"in", "r", stdin);
//	freopen(file"out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		Data x(w, 1); 
		f[u][v] = f[u][v] + x;
		f[v][u] = f[v][u] + x;
	}
	for (int i = 1; i <= n; i++) f[i][i] = Data(0, 1);
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) if (k != i)
			for (int j = 1; j <= n; j++) if (k != j) 
				f[i][j] = f[i][j] + f[i][k]*f[k][j];
	for (int v = 1; v <= n; v++) 
		for (int s = 1; s <= n; s++) if (s != v)
			for (int t = 1; t <= n; t++) if (t != v) {
				Data x = f[s][v]*f[v][t];
				if (x.dis == f[s][t].dis && x.cnt) 
					ans[v] += (double)x.cnt/f[s][t].cnt;
			}
	for (int i = 1; i <= n; i++) printf("%.3lf\n", ans[i]);
}
