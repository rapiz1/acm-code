#include <cstdio>
#include <cstdlib>
char cmd[1000];
int main() {
	int l = 1000, r = 1030, lk = 1, rk = 100;
	for (int i = l; i <= r; i++) {
		for (int j = lk; j <= rk; j++) {
			puts("-------");
			printf("n = %d k = %d:\n", i, j);

			sprintf(cmd, "./a.out %d %d >tasksauthor4.out", i, j);
			system(cmd);

			sprintf(cmd, "./co <tasksauthor4.out", i, j);
			system(cmd);

			sprintf(cmd, "./bu <tasksauthor4.out", i, j);
			int ret = system(cmd);
			if (!ret) break;
			getchar();
		}
	}
}
