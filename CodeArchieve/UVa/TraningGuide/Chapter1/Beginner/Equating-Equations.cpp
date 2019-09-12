#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <assert.h>
#define ALL(X) X.begin(), X.end()
typedef std::vector<int> EQ;
const int N = 40, L = 1 << 16;
char buf[L];
int sz, v[N], sm, tsz;
bool in[N];
EQ st[2], l, r;
void parse(char*& p, EQ& e) {
	while(*p && *p != '=') {
		if (isspace(*p)) p++;
		else if (isdigit(*p)) {
			int x;
			sscanf(p, "%d%n", &v[++sz], &x);
			p += x;
		}
		else e.push_back(*p++);
	}
}
bool dfs(int l, int s) {
//	if (s >= sm/2) return (s == sm/2 && st[0].size() == tsz);
	if (st[0].size() == tsz) return s == sm/2;
	else for (int i = l + 1; i <= sz; i++) {
		st[0].push_back(v[i]);
		in[i] = 1;
		if (dfs(i, s + v[i])) return 1;
		in[i] = 0;
		st[0].pop_back();
	}
	return 0;
}
int print(EQ& x, int t) {
	int s = 0;
	s += st[t].back();
	printf("%d", st[t].back()), st[t].pop_back();
	for (int i = 0; i < x.size(); i++) {
		int d = t^(x[i] == '-');
		s += st[d].back()*(x[i] == '+' ? 1 : -1);
		printf(" %c %d", x[i], st[d].back()), st[d].pop_back();
	}
	return s;
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	while (fgets(buf, L, stdin)) {
//		printf("LAST CHAR <NEWLINE> ?: %c", buf[strlen(buf)-1] == '\n' ? 'Y' : 'N');
//		buf[strlen(buf)-1]=0;
		memset(in, 0, sizeof(in));
		st[0].clear();
		st[1].clear();
		l.clear();
		r.clear();
		sm = tsz = sz = 0;
		char* p = buf;
		parse(p, l);
		parse(++p, r);
		for (int i = 0; i < l.size(); i++) tsz += l[i] == '+';
		for (int i = 0; i < r.size(); i++) tsz += r[i] != '+';
		++tsz;
		for (int i = 1; i <= sz; i++) sm += v[i];		
		if (sm%2 || !dfs(0, 0)) {
			printf("no solution\n");
			continue;
		}
		for (int i = 1; i <= sz; i++) if (!in[i]) st[1].push_back(v[i]);
		std::sort(ALL(st[0]), cmp);
		std::sort(ALL(st[1]), cmp);
		int x, y;
		x = print(l, 0);
		printf(" = ");
		y = print(r, 1);
//		printf("(%d %d)", x, y);
		assert(x == y);
		putchar('\n');
	}
}
