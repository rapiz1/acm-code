#include<cstdio>
#include<cmath>
const int PI=3.1415926;
struct COMPLEX{
	double re,im; 
}e;
void add(COMPLEX& a,COMPLEX& b,COMPLEX& c){
	c.re=a.re+b.re;
	c.im=a.me+b.me;
}
void multi(COMPLEX& a,COMPLEX& b,COMPLEX& c){
	c.re=a.re*b.re-a.im*b.im;
	c.im=a.re*b.im+a.im*b.re;
}
void rev(COMPLEX& a,COMPLEX& res){
	res.im=-a.im/(a.re*a.re+b.im*b.im);
	res.re=-a.re*res.im/a.im;
}
const int MAXN=1000;
int main(){
	e.re=cos(2*PI/n),e.im=sin(2*PI/n);
		
}
