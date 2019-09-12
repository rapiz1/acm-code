//dfs组合
#include<iostream>
using namespace std;
const int MAXN=111;
int n,k,a[MAXN];
void dfs(int idx,int cnt,int k) {
	if(cnt==k) {
		for(int i=0;i<k;i++) cout<<a[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=idx;i<=n;i++) a[cnt]=i,dfs(i+1,cnt+1,k);
}
int main() {
	cin>>n>>k;
	dfs(1,0,k);//在1..n中选k个数 
}
