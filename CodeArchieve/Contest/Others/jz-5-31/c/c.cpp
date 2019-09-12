#include <cstdio>
#include <utility>
typedef long long ll;
int n, m, q;
struct pa {
	int first, second, third;
	pa(int a = 0, int b = 0, int c = 0) {first = a, second = b, third = c;}
	pa operator+(pa x) {return pa(first + x.first, second + x.second, third);}
	bool operator==(pa x) {return first == x.first && second == x.second;}
	bool operator!=(pa x) {return !(*this == x);}
};
namespace subtask1{
	const int M = 15, K = 40;
	pa f[M][M][4][K], dir[M][M], dd[4];
	int gid(pa x) {
		if (x.first == 0) {
			if (x.second == 1) return 0;
			else return 2;
		}
		else if (x.first == -1) return 3;
		else return 1;
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			pa s, t;
			scanf("%d%d%d%d", &s.first, &s.second, &t.first, &t.second);
			pa de(t.first > s.first ? 1 : t.first < s.first ? -1 : 0, t.second > s.second ? 1 : t.second < s.second ? -1 : 0);
			while (s != t) {
				dir[s.first][s.second] = de;
				s.first += de.first, s.second += de.second;
			}
			dir[s.first][s.second] = de;
		}
		dd[0] = pa(0, 1), dd[1] = pa(1, 0), dd[2] = pa(0, -1), dd[3] = pa(-1, 0);
		for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) {
			if (dir[i][j] == pa(0, 0)) {
				for (int d = 0; d < 4; d++) {
					int x, y;
					f[i][j][d][0] = pa(x = i + dd[d].first, y = j + dd[d].second, d);
					if (x > m || y > m || x < 0 || y < 0) f[i][j][d][0] = pa(i, j, d);
				}
			}
			else {
				int x, y, d = gid(dir[i][j]);
				f[i][j][d][0] = pa(x = i + dir[i][j].first, y = j + dir[i][j].second, d);
				if (x > m || y > m || x < 0 || y < 0) f[i][j][d][0] = pa(i, j, d);
				for (int k = 0; k < 4; k++) if (k != d) f[i][j][k][0] = f[i][j][d][0];
			}
		}
		for (int k = 1; k < K; k++) {
			for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) {
				if (dir[i][j] != pa(0, 0)) {
					int d = gid(dir[i][j]);
					pa t = f[i][j][d][k - 1];
					f[i][j][d][k] = f[t.first][t.second][t.third][k - 1];
					for (int q = 0; q < 4; q++) if (q != d) f[i][j][q][k] = f[i][j][d][k];
				}
				else for (int d = 0; d < 4; d++) {
					pa t = f[i][j][d][k - 1];
					f[i][j][d][k] = f[t.first][t.second][t.third][k - 1];
				}
			}
		}
		scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			pa now;
			char cmd[2];
			ll t;
			scanf("%d%d%s%lld", &now.first, &now.second, cmd, &t);
			if (dir[now.first][now.second] != pa(0, 0)) now.third = gid(dir[now.first][now.second]);
			else {
				int d;
				switch(cmd[0]) {
					case 'U': d = 0; break;
					case 'R': d = 1; break;
					case 'D': d = 2; break;
					case 'L': d = 3; break;
				}
				now.third = d;
			}
			for (int i = K - 1; ~i; i--) if (t>>i&1) {
				int d = dir[now.first][now.second] == pa(0, 0) ? now.third : gid(dir[now.first][now.second]);
				now = f[now.first][now.second][d][i];
			}
			printf("%d %d\n", now.first, now.second);
		}
	}
}
namespace subtask2 {
	const int M = 1010;
	pa dir[M][M], dd[4];
	int gid(pa x) {
		if (x.first == 0) {
			if (x.second == 1) return 0;
			else return 2;
		}
		else if (x.first == -1) return 3;
		else return 1;
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			pa s, t;
			scanf("%d%d%d%d", &s.first, &s.second, &t.first, &t.second);
			pa de(t.first > s.first ? 1 : t.first < s.first ? -1 : 0, t.second > s.second ? 1 : t.second < s.second ? -1 : 0);
			while (s != t) {
				dir[s.first][s.second] = de;
				s.first += de.first, s.second += de.second;
			}
			dir[s.first][s.second] = de;
		}
		dd[0] = pa(0, 1), dd[1] = pa(1, 0), dd[2] = pa(0, -1), dd[3] = pa(-1, 0);
		scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			pa now;
			char cmd[2];
			int t;
			scanf("%d%d%s%d", &now.first, &now.second, cmd, &t);
			{
				int d;
				switch(cmd[0]) {
					case 'U': d = 0; break;
					case 'R': d = 1; break;
					case 'D': d = 2; break;
					case 'L': d = 3; break;
				}
				now.third = d;
			}
			while (t--) {
				pa ddd = dir[now.first][now.second];
				if (ddd == pa(0, 0)) ddd = dd[now.third];
				pa nxt = now + ddd;
				if (nxt.first > m || nxt.first < 0 || nxt.second > m || nxt.second < 0) break;
				now = nxt;
				now.third = gid(ddd);
			}
			printf("%d %d\n", now.first, now.second);
		}
	}
}
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n <= 10) subtask1::solve();
	else subtask2::solve();
}
