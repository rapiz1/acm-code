// Mannachar 求最长回文子串
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000+10;
int p[MAXN],len;
char a[MAXN],b[MAXN*2];
int main(){
	cin>>a;
	int len=strlen(a);
	//init
	for(int i=0;i<=len;i++) b[2*i+1]='#',b[2*i+1+1]=a[i];
	b[0]='$';
	len=strlen(b);
	//p[]
	int mx=0,id=0,mxid=0;//p[mxid]最大 
	for(int i=1;i<=len;i++){
		if(mx>i) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		while(p[i]<=i&&b[i-p[i]]==b[i+p[i]]) p[i]++;
		if(p[i]+i>mx) mx=p[i]+i,id=i;
		if(p[i]>p[mxid]) mxid=i;
	}
	//output
	for(int j=p[mxid]-1;j>=0;j--)
		if(b[mxid-j]!='#') cout<<b[mxid-j];
	for(int j=1;j<p[mxid];j++)
		if(b[mxid-j]!='#') cout<<b[mxid+j];
}
