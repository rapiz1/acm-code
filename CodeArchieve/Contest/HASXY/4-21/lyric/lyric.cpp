#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>
using namespace std;
const int N = 2010;
struct Lines {
	int mm, ss;
	string w;
	bool operator<(const Lines& rhs)const {
		if (mm != rhs.mm) return mm < rhs.mm;
		else if (ss != rhs.ss) return ss < rhs.ss;
		else if (w.size() != rhs.w.size()) return w.size() < rhs.w.size();
		else return w < rhs.w;
	}
	bool time(const Lines& rhs)const {return mm == rhs.mm && ss == rhs.ss;}
}st[N];
int th[N], tot;
string tmp, name;
int cmp(int i, int j) {return st[i] < st[j];}
int main() {
	freopen("lyric.in", "r", stdin);
	freopen("lyric.out", "w", stdout);
	ios::sync_with_stdio(false);
	while (getline(cin, tmp)) {
		if (tmp[1] == 'n') name = tmp.substr(6);
		else {
			st[++tot].w = tmp.substr(7);
			st[tot].mm = (tmp[1] - '0')*10 + tmp[2] - '0';
			st[tot].ss = (tmp[4] - '0')*10 + tmp[5] - '0';
		}
	}
	for (int i = 1; i <= tot; i++) th[i] = i;
	std::sort(th + 1, th + 1 + tot, cmp);
	cout << string(8, ' ') << name << endl;
	for (int i = 1, j; i <= tot; i = j) {
		for(j = i; j <= tot && st[th[j]].time(st[th[i]]); j++);
		for (int k = i; k < j; k++) cout << st[th[k]].w;
		cout << endl;
	}
}
