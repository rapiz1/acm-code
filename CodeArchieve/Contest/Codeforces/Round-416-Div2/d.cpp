#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
typedef std::pair<int, int> pa;
const int N = 110;
int n, m, ud = -1, lr = -1, nx = 1, ny = 1, dx, dy;
char mm[N][N];
pa prev[N][N];
bool vis[N][N];
std::queue<pa> q;
void left() {
	if (lr == -1) {
		puts("L");
		fflush(stdout);
		int x, y; scanf("%d%d", &x, &y);
		if (y == ny - 1) lr = 0, ny--;
		else {
			lr = 1;
			int dy = ny - 1;
		 	left();
			if (ny == dy) return;
		 	left();
		}
		return;
	}
	puts(lr ? "R" : "L");
	fflush(stdout);
	scanf("%d%d", &nx, &ny);
}
void right() {
	if (lr == -1) {
		puts("R");
		fflush(stdout);
		int x, y; scanf("%d%d", &x, &y);
		if (y == ny + 1) lr = 0, ny++;
		else {
			lr = 1;
			int dy = ny + 1;
		 	right();
			if (ny == dy) return;
		 	right();
		}
		return;
	}
	puts(lr ? "L" : "R");
	fflush(stdout);
	scanf("%d%d", &nx, &ny);
}
void up() {
	if (ud == -1) {
		puts("U");
		fflush(stdout);
		int x, y; scanf("%d%d", &x, &y);
		if (x == nx - 1) ud = 0, nx--;
		else {
			ud = 1;
			int dx = nx - 1;
		 	up();
			if (nx == dx) return;
		 	up();
		}
		return;
	}
	puts(ud ? "D" : "U");
	fflush(stdout);
	scanf("%d%d", &nx, &ny);
}
void down() {
	if (ud == -1) {
		puts("D");
		fflush(stdout);
		int x, y; scanf("%d%d", &x, &y);
		if (x == nx + 1) ud = 0, nx++;
		else {
			ud = 1;
			int dx = nx + 1;
		 	down();
			if (nx == dx) return;
		 	down();
		}
		return;
	}
	puts(ud ? "U" : "D");
	fflush(stdout);
	scanf("%d%d", &nx, &ny);
}
std::vector<pa> line;
void go(std::vector<pa>& path) {
	for (int i = 1; i < (int)path.size(); i++) {
		pa nn = path[i];
		if (nn.first == nx + 1) down();
		else if (nn.first == nx - 1) up();
		else if (nn.second == ny + 1) right();
		else if (nn.second == ny - 1) left();
		if (nx == -1 && ny == -1) return;
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", mm[i] + 1);
	}
	vis[1][1] = 1;
	q.push(std::make_pair(1, 1));
	while (!q.empty()) {
		pa u = q.front(); q.pop();
		for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx*dy == 0 && dx + dy) {
			int x = u.first + dx, y = u.second + dy;
			if (1 <= x && x <= n && 1 <= y && y <= m && mm[x][y] != '*' && !vis[x][y]) {
				prev[x][y] = u;
				vis[x][y] = 1;
				q.push(std::make_pair(x, y));
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (mm[i][j] == 'F') {dx = i, dy = j;break;}
	line.push_back(std::make_pair(dx, dy));
	for (int x = dx, y = dy; !(x == 1 && y == 1); ) {
		pa d = prev[x][y];
		line.push_back(d);
		x = d.first, y = d.second;
	}
	std::reverse(line.begin(), line.end());
	go(line);
}
