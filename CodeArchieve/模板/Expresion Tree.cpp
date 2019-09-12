#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=10000;
char f[MAXN];
int lch[MAXN],rch[MAXN],op[MAXN],sz;
int mkt(int s,int e){
	if((f[s]=='(')&&(f[e]==')')) s++,e--;
	int cr=++sz,i=s,ln=0,rn=0;
    if(s==e) {
        op[cr]=f[s];
        return cr;
    }
    for(i=s;i<=e;i++) {
        if(f[i]=='(') ln++;
        else if(f[i]==')') rn++;
        else if((f[i]=='+')||(f[i]=='-'))break;
    }
    if(i>e)
        for(i=s;i<=e;i++)
            if((f[i]=='*')||(f[i]=='/')) break;
    lch[cr]=mkt(s,i-1),rch[cr]=mkt(i+1,e),op[cr]=f[i];
    return cr;
}
void dfs(int c){
	if(lch[c]+rch[c]==0) printf("%c ",op[c]);
	else {
		dfs(lch[c]);
		printf("%c ",op[c]);
		dfs(rch[c]);
	}
}
int main(){
	cin>>f;
	int root=mkt(0,strlen(f)-1);
	dfs(root);
}
