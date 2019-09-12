#include <cstdio>
#include <set>
const int N = 1e5 + 10;
typedef long long ll;
int n;
ll a[N];
std::set<ll> st;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
	bool f = 0;
	for (int i = 1; i <= n; i++)  {
		st.insert(a[i] - a[i - 1]);
		if (a[i] == a[n] - a[i]) f = 1;
		else {
			ll d = 2*a[i] - a[n];
			if (d%2 == 0 && st.find(d/2) != st.end()) f = 1;
		}
	}
	st.clear();
	for (int i = n; i >= 1; i--)  {
		st.insert(a[i] - a[i - 1]);
		if (a[i - 1] == a[n] - a[i - 1]) f = 1;
		else {
			ll d = a[n] - 2*a[i - 1];
			if (d%2 == 0 && st.find(d/2) != st.end()) f = 1;
		}
	}
	puts(f?"YES":"NO");
}
