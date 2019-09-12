#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> revn;
int main() {
	freopen("input", "r", stdin);
	for (ll a, b, p; cin >> p >> a >> b;) {
        //if (!a && b) puts("no solution")!!!!
		revn.clear();
		int sq = ceil(sqrt(p));
		ll g = b;
		for (int i = 0; i <= sq; i++, g = g*a%p) revn[g] = i;
		g = 1;
		for (int i = 1; i <= sq; i++) g = g*a%p;
		ll gg = g;
		bool found = 0;
		for (int i = 1; i <= sq; i++, gg = gg*g%p) if (revn.count(gg)) {
			found = 1;
			printf("%d\n", i*sq - revn[gg]);
			break;
		}
		if (!found) puts("no solution");
	}
}
