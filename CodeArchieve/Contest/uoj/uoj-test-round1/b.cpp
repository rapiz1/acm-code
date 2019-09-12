#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
const int N = 3e5 + 10;
typedef long long ll;
struct Task {
	ll t, s, p, id;
	bool operator<(const Task& rhs)const {return p < rhs.p;}
}st[N];
bool stime(const Task& a, const Task& b){
	if (a.t != b.t) return a.t < b.t;
	else return a.p > b.p;
}
std::priority_queue<Task> q;
std::vector<int> ap;
int n, pos, ans;
ll t, fin[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &st[i].t, &st[i].s, &st[i].p), ap.push_back(st[i].p), st[i].id = i;
	scanf("%lld", &t);
	st[++n] = (Task){ll(1e18 + 1), 0, -2};
	std::sort(st + 1 , st + 1 + n, stime);
	ap.push_back(1e9 + 2);
	std::sort(ap.begin(), ap.end());
	for (int i = 1; i <= n; i++) {
		ll x = st[i].t - st[i - 1].t;
		while (x && !q.empty()) {
			Task u = q.top(); q.pop();
			ll y = std::min(x, u.s);
			x -= y;
			u.s -= y;
			if (u.s) q.push(u);
		}
		if (st[i].p == -1) {pos = i;break;}
		q.push(st[i]);
	}
	for (int i = pos + 1; i <= n && st[i].t <= t; i++) q.push(st[i]);
	ll x = t - st[pos].t - st[pos].s;
	while (x && !q.empty()) {
			Task u = q.top(); q.pop();
			x -= u.s;
	}
	for (int i = 0, j = q.empty() ? 0 : q.top().p; i < (int)ap.size(); i++) {
		if (ap[i] - 1 > j && (!i || ap[i - 1] != ap[i] - 1)) {
			ans = ap[i] - 1;
			break;
		}
	}
	printf("%d\n", ans);
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++) {
		ll x = st[i].t - st[i - 1].t;
		while (x && !q.empty()) {
			Task u = q.top(); q.pop();
			int y = std::min(x, u.s);
			x -= y;
			u.s -= y;
			if (u.s) q.push(u);
			else fin[u.id] = st[i].t - x;
		}
		if (st[i].p == -1) st[i].p = ans;
		q.push(st[i]);
	}
	for (int i = 1; i < n; i++) printf("%lld ", fin[i]); 
}
