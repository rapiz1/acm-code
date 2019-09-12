#include <cstdio>
#include <cstring>
#include <stack>
const int N = 2e5 + 10;
int n, a[N], m;
std::stack<int> st;
int main() {
	while (scanf("%d", &n) == EOF) {
		memset(a, 0, sizeof(a));
		for (int i = 1, x; i <= n; i++) scanf("%d", &x), st.push_back(x);
		while (!st.empty()) {
			int x = st.top() + 1;
			st.pop();
			int p, s, i;
			for (p = 1, s = 0, i = 0, t; (t = p + (1 << i)) < n && s + a[t] < x;) p = t, s += a[t];
			printf("%d ", p);
		}
		putchar('\n');
	}
}
