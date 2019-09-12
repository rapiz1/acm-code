#include <cstdio>
const int V = 1e6 + 1, L = 1e6 + 1;
int n, ch[V][26], fail[V], sz, cnt[V], q[V], h, t;
char wd[210][L];
inline int get(char* p) {
	int now = 0;
	for(; *p; p++) {
		if (!ch[now][*p - 'a']) ch[now][*p - 'a'] = ++sz;
		now = ch[now][*p - 'a'];
	}
	return now;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", wd[i]);
		get(wd[i]);
	}
	for (int i = 0; i < 26; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int x = q[h++];
		for (int i = 0; i < 26; i++) if (ch[x][i]) {
			q[t++] = ch[x][i];
			int p = fail[x];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[x][i]] = ch[p][i];
		}else ch[x][i] = ch[fail[x]][i];
	}
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (char* p = wd[i]; *p; p++) {
			now = ch[now][*p - 'a'];
			cnt[now]++;
		}
	}
	for (;t;t--) cnt[fail[q[t]]] += cnt[q[t]];
	for (int i = 1; i <= n; i++) printf("%d\n", cnt[get(wd[i])]);
}
