#include <cstdio>
const char border[] = "+-----+";
int d;
char buf[100];
int main() {
	scanf("%d", &d);
	puts(border);
	buf[0] = '|';
	buf[6] = '|';
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) buf[j]= ' ';
		if (i == 1) {
			if (d >= 90) buf[4] = '4', buf[5] = 'G';
			else if (d >= 60) buf[4] = '3', buf[5] = 'G';
			else buf[5] = 'E';
		}
		if (i <= d/20) for (int j = 1; j <= i; j++) buf[j] = '-';
		puts(buf);
	}
	puts(border);
}
