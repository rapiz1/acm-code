#include<iostream>
int x,y,a,b,m,d;
void ex_gcd(int a,int b,int& d,int& x,int& y){
	if(b==0) d=a,x=1,y=0;
	else {
		ex_gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
int main(){
	cin>>a>>b>>m;
	ex_gcd(a,b,d,x,y);
	cout<<x<<' '<<y;
}
