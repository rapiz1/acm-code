#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;	
	while (t--) {
		int n;cin >> n;
		if (n >= 4) {
			if (n) puts(n&1?"No":"Yes");
			else puts("No");
		}
		else puts("No");
	}
}
