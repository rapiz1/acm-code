#include <bits/stdc++.h>
using namespace std;
const char s[] = "I am a good ACMer";
int main() {
	int t; cin >> t;
	while (t--) {
		int num; cin >> num;
		num%=10;
		while (num--) cout << s << endl;
		cout << endl;
	}
}
