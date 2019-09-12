#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define s 0
#define t 15010
#define inf 1000000000
 
using namespace std;
 
struct edge
{
    int x , y , cap , cost;
    edge() {}
    edge( int x , int y , int cap , int cost ) : x( x ) , y( y ) , cap( cap ) , cost( cost ) {}
} e[1000000];
 
int dist[t + 2] , pre[t + 2] , number[t + 2] , pos , n , cnt;
bool use[t + 2];
vector < int > linker[t + 2];
 
inline void addedge( int x , int y , int cap , int cost )
{
    linker[x].push_back( pos );
    e[ pos++ ] = edge( x , y , cap , cost );
    linker[y].push_back( pos );
    e[ pos++ ] = edge( y , x , 0 , -cost );
}
 
#define cur e[ linker[ now ][i] ].y
#define v e[ linker[ now ][i] ].cost
inline bool spfa()
{
    queue < int > q;
    q.push( s );
    memset( dist , 0 , sizeof( dist ) );
    dist[s] = 1;
    int now;
    while( !q.empty() )
    {
        use[ now = q.front() ] = 0 , q.pop();
        for( register int i = 0 ; i < linker[ now ].size() ; i++ )
            if( e[ linker[ now ][i] ].cap && dist[ cur ] < dist[ now ] + v )
            {
                dist[ cur ] = dist[ now ] + v;
                pre[ cur ] = now , number[ cur ] = i;
                if( !use[ cur ] )
                {
                    use[ cur ] = 1;
                    q.push( cur );
                }
            }
    }
    return dist[t] > 1;
}
#undef cur
#undef v
 
inline int flow()
{
    int low = inf , now = t , pos , ans = 0;
    while( now != s )
        low = min( low , e[ linker[ pre[ now ] ][ number[ now ] ] ].cap ) , now = pre[ now ];
    now = t;
    while( now != s )
    {
        pos = linker[ pre[ now ] ][ number[ now ] ];
        e[ pos ].cap -= low;
        e[ pos ^ 1 ].cap += low;
        ans += low * e[ pos ].cost;
        now = pre[ now ];
    }
    return ans;
}
#undef s
 
struct Node
{
    int size , value;
    Node * left , * right;
    Node( int s , int v , Node * a , Node * b ) : size( s ) , value( v ) , left( a ) , right( b ) {}
} * root;
 
int x , y , z , ans;
 
void modify( int a , int l , int r , Node * cur )
{
    if( cur -> size == r - l + 1 ) addedge( a , cur -> value , 1 , 0 );
    else if( l > cur -> left -> size ) modify( a , l - cur -> left -> size , r - cur -> left -> size , cur -> right );
    else if( cur -> left -> size >= r ) modify( a , l , r , cur -> left );
    else modify( a , l , cur -> left -> size , cur -> left ) , modify( a , 1 , r - cur -> left -> size , cur -> right );
}
 
Node * build( int l , int r )
{
    if( l == r ) return addedge( ++cnt , t , 1 , 0 ) , new Node( 1 , cnt , 0 , 0 );
    Node * cur = new Node( r - l + 1 , ++cnt , build( l , ( l + r ) >> 1 ) , build( ( ( l + r ) >> 1 ) + 1 , r ) );
    addedge( cur -> value , cur -> left -> value , inf , 0 ) , addedge( cur -> value , cur -> right -> value , inf , 0 );
    return cur;
}
 
int main()
{
    scanf( "%d" , &n );
    Node * root = build( 1 , 5000 );
    for( register int i = 1 ; i <= n ; i++ )
    {
        scanf( "%d %d %d" , &x , &y , &z );
        modify( cnt + i , x , y - 1 , root );
        addedge( 0 , cnt + i , 1 , z );
    }
		fprintf(stderr, "%d\n", pos);
    while( spfa() )
        ans += flow();
    cout << ans << endl;
    return 0;
}
