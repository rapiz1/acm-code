#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N = 60;
int n, k, cnt;
bool can[N];
string peo[N];
char cmd[100], sss[N];
void name(int th) {
	++cnt;
	int i, x;
	for (i = 0, x = cnt; x; i++) {
		sss[i] = (x%26 + 'a');
		x/=26;
	}
	reverse(sss, sss + i);
	sss[0] += 'A' - 'a';
	sss[i] = 0;
	peo[th] = sss;
}
int main() {
	//freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i < k; i++) name(i);
	for (int i = k; i <= n; i++) {
		scanf("%s", cmd);
		if (cmd[0] == 'N') {
			peo[i] = peo[i - k + 1];
		}
		else name(i);
	}
	for (int i = 1; i <= n; i++) printf("%s ", peo[i].c_str());
}
