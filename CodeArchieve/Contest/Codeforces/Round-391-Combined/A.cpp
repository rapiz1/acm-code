#include <cstdio>
#include <algorithm>
using std::min;
const int L = 1e5 + 10;
char buf[L];
int cnt[256];
int main() {
	fgets(buf, L, stdin);
	for (char* s = buf; *s;) cnt[*s++]++;
	int r = cnt['B'];
	r = min(r, cnt['u']/2);
	r = min(r, cnt['l']);
	r = min(r, cnt['b']);
	r = min(r, cnt['a']/2);
	r = min(r, cnt['s']);
	r = min(r, cnt['r']);
	printf("%d",r );
}
