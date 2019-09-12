#include <cstdio>
int main() {
	for (int n; scanf("%d", &n), n; ) printf("%s\n", n%2 ? "Bob" : "Alice");
}
