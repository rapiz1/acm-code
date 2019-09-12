#include<iostream>
using namespace std;
int qpow(int a,int r){
	int res=1,fac=a;
	while(r){
		if(r&1) res*=fac;
		fac*=fac,r>>=1;
	}
	return res;
}
int main(){
	int a,r;
	cin>>a>>r;
	cout<<qpow(a,r);
}
