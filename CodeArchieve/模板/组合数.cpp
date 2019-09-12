#include<iostream> 
#include<cstring>
using namespace std;
const int MAXN=100;
long long c[MAXN][MAXN];
int n,cnt;
int main(){
	for(int i=0;i<MAXN;i++) c[i][0]=1;
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) printf("c(%d,%d)=%lld\n",i,j,c[i][j]),cnt++;
	printf("cnt:%d",cnt);
}
