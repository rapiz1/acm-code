#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10; 
struct B{int i, w, v;}b[N];
bool cmp(const B& a, const B& b){return a.w < b.w;}
bool cmp2(const B& a, const B& b){return a.i < b.i;}
int n, a[N], l, r;
int main() {
//	freopen("input", "r", stdin);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i].w, b[i].i = i;
	sort(b + 1, b + 1 + n, cmp);
	int mx = -2e9;
	for (int i = 1; i <= n; i++) {
		int k = b[i].i, v = max(mx + 1, l - a[k]);
		if (v > r - a[k]) {
			puts("-1");
			return 0;
		}
		mx = max(mx, b[i].v = v);
	}
	sort(b + 1, b + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) printf("%d ", a[i] + b[i].v);
}
