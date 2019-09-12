
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
const int CLKSPMS = CLOCKS_PER_SEC / 1000;
const int MAXN = 50;
const int MAXR = 129;

int n, m, a[MAXN], r[MAXR] = {0}, maxr = 0, ans = 0;

void dfs1(int,int); // declaration
void dfs2( int nowa, int nowr, int tot, int left ) {
	if( clock() / CLKSPMS >= 950 ) {
		printf( "%d\n", ans );
		exit(0);
	}
	while( nowr <= maxr && !r[nowr] ) ++nowr;
	if( nowr > maxr || left < nowr ) {
		dfs1(nowa+1, tot);
		return;
	}
	for( int i = 0; left >= i*nowr && i <= r[nowr]; ++i ) {
		r[nowr] -= i;
		dfs2(nowa, nowr+1, tot+i, left-i*nowr);
		r[nowr] += i;
	}
}
void dfs1( int now, int tot ) {
	ans = max(ans, tot);
	if( now == n ) return;
	dfs2(now, 1, tot, a[now]);
}

int main() {
	freopen( "fence.in", "r", stdin );
//	freopen( "fence.out", "w", stdout );
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%d", a+i );
	sort(a, a+n);
	scanf( "%d", &m );
	for( int i = 0; i < m; ++i ) {
		int x; scanf( "%d", &x );
		++r[x];
		maxr = max(maxr, x);
	}
	dfs1(0,0);
	printf( "%d\n", ans );
	return 0;
}
