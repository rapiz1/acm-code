#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string a[60];
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) return a > b;
	else return a + b > b + a;
}
int main() {
	while (cin >> n) {
		if (!n) break;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) cout << a[i];
		cout << endl;
	}	
}
