#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;
struct Dir {
	map<string, Dir*> ch;
	Dir* fa;
	string name;
}*root;
int n, m;
Dir* go(string& str) {
	Dir* pos = root;
	for (int i = 1, j; i < (int)str.size(); i = j + 1) {
		for (j = i; j < (int)str.size() && str[j] != '/'; j++) ;
		string tmp = str.substr(i, j - i);
		if (pos->ch.count(tmp)) ;
		else pos->ch[tmp] = new Dir, pos->ch[tmp]->name = tmp, pos->ch[tmp]->fa = pos;
		pos = pos->ch[tmp];
	}
	return pos;
}
vector<string> ans;
string s, t;
int main() {
//	freopen("input", "r", stdin);
	cin >> n >> m;
	root = new Dir;
	while (n--) {
		cin >> s >> t;
		string tmp = s.substr(s.find_last_of('/') + 1);
		go(s)->fa->ch[s.substr(s.find_last_of('/') + 1)] = go(t);
	}
	while (m--) {
		ans.clear();
		cin >> s;
		Dir* pos = go(s);
		for (;pos != root; pos = pos->fa)
		 	ans.push_back(pos->name);
		cout << '/';
		for (int i = (int)ans.size() - 1; ~i; i--) {
			cout << ans[i];
			if (i) cout << '/';
		}
		cout << endl;
	}
}
