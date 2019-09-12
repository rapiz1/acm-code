#include <cstdio>
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"
typedef long long ll;
int ins[100][100];
ll f(ll a,ll b)
{
	if (ins[a][b]) return -1e9;
	ins[a][b] = 1;
	ll ret;
	if(a==b) ret = 0;
	else if(a>b) ret = f(a-b,b+b)+1;
	else ret= f(a+a,b-a)+1;
	ins[a][b] = 0;
	return ret;
}
int n;
int main() {
	scanf("%d", &n);
//	n = 5;
	for (int i = 1; i <= n; i++, putchar('\n')) for (int j = 1; j <= n; j++) {
		ll x = f(i, j);
		if (x < -100) x = -1, printf("* ");
		else printf(RED "%lld " NONE, x);
	}
}
