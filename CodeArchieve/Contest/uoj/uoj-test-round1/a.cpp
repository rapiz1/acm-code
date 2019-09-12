#include <cstdio>
#include <algorithm>
#include <string>
int n;
char buf[110];
std::string a[10010];
bool cmp(const std::string& a, const std::string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else return a < b;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", buf), a[i] = buf;
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) printf("%s\n", a[i].c_str());
}
