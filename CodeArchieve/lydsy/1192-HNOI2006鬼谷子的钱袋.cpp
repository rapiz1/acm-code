#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1;i<n;i<<=1) ans++;
	printf("%d\n", ans);
}
