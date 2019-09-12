#include <cstdio>
#include <vector>
const int N = 200, K = 3;
typedef long long ll;
int n, len, ans;
char sour[N];
const int C = 2, MOD[C] = {1000003, 2000003}, S = 2000004, F = 31;
struct HT {
	bool ext[S][2];
	int calc(char* s, int m) {
		int r = 0;
		for (;*s; s++) 
			r = (r*F + *s - 'a' + 1)%m;
		return r;
	}
	void in(char* s) {
		for (int i = 0; i < C; i++) ext[calc(s, MOD[i])][i] = 1;
	}
	bool count(char* s) {
		for (int i = 0; i < C; i++) if (!ext[calc(s, MOD[i])][i]) return 0;
		return 1;
	}
}ht;
struct Str{
	char s[N];
	std::vector<int> nxt[N][26];
	void build() {
		scanf("%s", s + 1);
		for (int i = 0; i <= n; i++) {
			for (int c = 0; c < 26; c++) {
				for (int j = i + 1; j <= n; j++) if (s[j] == c + 'a') nxt[i][c].push_back(j);
			}
		}
	}
	void dfs(int);
	bool find(int p, char* s) {
		if (!*s) return 1;
		if (nxt[p][int(*s - 'a').empty()) return 0;
        else {
			if (find(nxt[p][int(*s - 'a')][i], s + 1)) return 1;
		}
		return 0;
	}
}str[3];
void Str::dfs(int p) {
	if (p > n) {
		if (!len) return;
		for (int i = 1; i < K; i++) if (!str[i].find(0, sour)) return;
		if (!ht.count(sour)) ans++, ht.in(sour);
//		puts(sour);
//		ans++;
	}
	else {
		/*
		sour[len++] = s[p];
		dfs(p + 1);
		sour[--len] = 0;
		dfs(p + 1);
		*/
		for (int i = 0, flag = 0; i < 26; i++) if (nxt[p][i].empty()) {
			if(!flag) flag = 1, dfs(n + 1);
		}
		else {
			sour[len++] = i + 'a';
			dfs(nxt[p][i][0]);
			sour[--len] = 0;
		}
		dfs(n + 1);
	}
}

int main() {
	freopen("zwieback.in", "r", stdin);
	freopen("zwieback.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < K; i++) str[i].build();
	str[0].dfs(0);
	printf("%d\n", ans);
}
