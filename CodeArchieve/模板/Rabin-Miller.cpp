#include<cstdio>
#include<cmath>
#include<cstdlib> 
#include<ctime>
typedef long long ll;
ll lrand(ll l,ll r){return rand()*rand()%(r-l+1)+l;}
ll qpowm(ll a,ll r,ll m){
	ll ret=1;
	while(r){
		if(r&1) ret=ret*a%m;
		a=a*a%m,r>>=1;
	}
	return ret;
}
bool robin(int x){
	ll d=x-1,s=0;
	while(!(d%2)) d>>=1,s++;
	ll a=lrand(1,x-1),t;
	if((t=qpowm(a,d,x))==1) return true;
	for(int i=0;i<s;i++){
		if(t==x-1) return true;
		t=t*t%x;
	}
	return false;
}
bool PrimeTest(int n){
	static const int T=20;
	for(int i=1;i<=T;i++) if(!robin(n)) return false;
	return true;
}
bool brute(int x){
	int upb=sqrt(x);
	for(int i=2;i<=upb;i++) if(!(x%i)) return false;
	return true;
} 
int main(){
	srand(time(NULL));
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) if(brute(i)!=PrimeTest(i)) printf("%d\n",i);
} 
