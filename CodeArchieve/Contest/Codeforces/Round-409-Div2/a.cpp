#include <bits/stdc++.h>
using namespace std;
const int L = 110;
char s[L];
int n, k[L], v[L], ans, na;
int main()  {
//	freopen("input", "r" ,stdin);
	scanf("%s",s);
	n = strlen(s);
	for (int i = 0; i < n; i++) if (s[i] == 'V' && s[i + 1] == 'K') ans++;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') {
			if (i > 0) na = max(na, (s[i - 1] == 'V') - (s[i + 1] == 'K') + ans);
		}
		else {
			int cc = ans;
			if (i > 0) cc -= s[i - 1] == 'V';
			cc += s[i + 1] == 'K';
			na = max(na, cc);
		}
	}
	cout << max(ans, na);
}
