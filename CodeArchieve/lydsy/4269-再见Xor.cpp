#include <cstdio>
#include <algorithm>
int r[32], n, ret;
int main() {
	scanf("%d", &n);
	for (int i = 1 ,x; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 31; ~j; j--) if (x>>j&1)
		 if (r[j]) 	x ^= r[j];
		 else {r[j] = x;break;}
	}
	for (int i = 0; i <= 31; i++)
		for (int j = i - 1; ~j; j--) 
			if (r[i]>>j&1) r[i] ^= r[j];
	for (int i = 31; ~i; i--) ret = std::max(ret, ret^r[i]);
	printf("%d ", ret);
	int bf = ret;
	for (int i = 0; i <= 31; i++) if (r[i]) {
		ret^=r[i];
		break;
	}
//	if (bf == ret) ret = 0;
	printf("%d\n", ret);
}
