#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#define file(x) "ACautomata."#x
const int V = 510, N = 15, L = 55;
int n, ch[V][26], cnt[V], fail[V], sz, sk[V], top;
char s[N][L];
std::queue<int> q;
int get(char* c) {
	int p = 0;
	for (;*c; c++) {
		if (!ch[p][*c - 'a']) ch[p][*c - 'a'] = ++sz;
		p = ch[p][*c - 'a'];
	}
	return cnt[p];
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s[i]), get(s[i]);
	for (int i = 0; i < 26; i++) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) if (ch[u][i]) {
			q.push(ch[u][i]);
			sk[++top] = ch[u][i];
			int p = fail[u];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[u][i]] = ch[p][i];
		}
		else ch[u][i] = ch[fail[u]][i];
	}
	int p = 0;
	char c = getchar();
	while (!isalpha(c)) c = getchar();
	for (; isalpha(c); c = getchar()) cnt[p = ch[p][c - 'a']]++;
	for (;top; top--) cnt[fail[sk[top]]] += cnt[sk[top]];
	for (int i = 1; i <= n; i++) printf("%s %d\n", s[i], get(s[i]));
}
