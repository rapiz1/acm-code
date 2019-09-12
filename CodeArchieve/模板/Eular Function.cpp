#include<iostream>
using namespace std;
const int MAXN=10000+10;
int phi[MAXN],n;
void makephi(){
	for(int i=1;i<=n;i++) if(!phi[i]) 
			for(int j=i;j<=n;j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
}
int main(){
	cin>>n;
	makephi();
}
