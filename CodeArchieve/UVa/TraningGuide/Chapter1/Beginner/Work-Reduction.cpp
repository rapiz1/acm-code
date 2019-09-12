#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
struct S{
	std::string name;
	int c;
	bool operator<(const S&b)const {return c < b.c || (c == b.c && name < b.name);}
}s[101];
char name[200];
int n, m, t;
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int ks = 1; ks <= T; ks++) {
		printf("Case %d\n", ks);
		scanf("%d%d%d", &n, &m, &t);
		getchar();
		for (int i = 1; i <= t; i++) {
			int a, b;
			fgets(name, 200, stdin);
			char* p = strchr(name, ':');
			*p = 0;
			sscanf(p + 1, "%d,%d", &a, &b);
			s[i].name = std::string(name);
			int x = n, c = 0;
			while (x > m) {
				if (x/2 >= m) c += std::min((x+1)/2*a, b), x/=2;
				else c += a, x--;
			}	
			s[i].c = c;
		}
		std::sort(s + 1, s + 1 + t);
		for (int i = 1; i <= t; i++) printf("%s %d\n", s[i].name.c_str(), s[i].c); 
	}
}
