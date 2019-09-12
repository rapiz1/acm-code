#include <cstdio>
int a[2];
int main() {
	scanf("%d%d", a, a + 1);
	for (int i = 0; 1; i++) {
		a[i&1] -= i + 1;
		if (a[i&1] < 0) {
			puts(i%2 == 0 ? "Vladik" : "Valera");
			break;
		}
	}
}
