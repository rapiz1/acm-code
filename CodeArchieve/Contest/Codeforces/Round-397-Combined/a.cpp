#include <cstdio>
#include <cstring>
const int U = 3e4;
int n, s, chu[U], ru[U];
int zip(char* s) {
	int r = 0;
	while (*s) r = r*31 + *s++ - 'A';
	return r;
}
char buf[100];
int main() {
	scanf("%d", &n);
	scanf("%s", buf);
	s = zip(buf);
	for (int i = 1; i <= n; i++) {
		scanf("%s", buf);
		int j;
		for (j = 0; buf[j] != '-'; j++);
		buf[j] = 0;
		chu[zip(buf)]++;
		ru[zip(buf + j + 2)]++;
	}
	if (chu[s] > ru[s]) puts("contest");
	else puts("home");
}
