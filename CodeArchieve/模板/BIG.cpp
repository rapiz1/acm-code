#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int BASE=1e4,WIDTH=4;
struct BIG{
	int a[1000],s,f;//1...s
	BIG(){memset(this,0,sizeof(*this));this->f=1;}
	BIG(string& str){
		memset(this,0,sizeof(*this));
		if(str[0]=='-') f=-1,str.erase(str.begin());
		else f=1;
		for(int i=str.size();i>0;i-=WIDTH){//³¬Î²i 
			int t=max(i-WIDTH,0);
			sscanf(str.substr(t,i-t).c_str(),"%d",&(this->a[++(this->s)]));
		}
	}
};
ostream& operator<<(ostream& os,const BIG& t){
	if(t.f<0) printf("-");
	printf("%d",t.a[t.s]);
	for(int i=t.s-1;i>=1;i--) printf("%04d",t.a[i]);
	return os;
}
bool operator<(const BIG&a,const BIG&b){
	if(a.s!=b.s) return a.s<b.s;
	for(int i=a.s;i>=1;i--)
		if(a.a[i]<b.a[i]) return true;
		else if(a.a[i]>b.a[i]) return false;
	return false;
}
bool operator==(const BIG&a,const BIG&b){
	if(a.s!=b.s) return false;
	for(int i=a.s;i>=1;i--) if(a.a[i]!=b.a[i]) return false;
	return true;
}
bool operator>(const BIG&a,const BIG&b){
	return !(a<b)&&!(a==b);
}
BIG operator-(const BIG& a,const BIG& b){
	//a>b a-b=a-b 
	//a<b a-b=-(b-a)
	BIG c;
	c.s=max(a.s,b.s);
	if(a<b) c=b-a,c.f=-c.f;
	else{
		int j,i;
		for(j=0,i=1;i<=c.s;i++) {
			c.a[i]=a.a[i]-b.a[i]-j;
			if(c.a[i]<0) c.a[i]+=BASE,j=1;
			else j=0;
		}
		while(c.s>1&&c.a[c.s]==0) c.s--;
	}
	return c;
}
BIG operator+(const BIG& a,const BIG& b){
	if(a.f==1&&b.f==-1) return a-b;
	else if(a.f==-1&&b.f==1) return b-a;
	//a>=0&&b>=0
	BIG c;
	c.s=max(a.s,b.s);
	int g,i;
	for(g=0,i=1;i<=c.s;i++){
		c.a[i]=a.a[i]+b.a[i]+g;
		g=c.a[i]/BASE;
		c.a[i]%=BASE;
	}
	while(g) c.a[++c.s]=g%BASE,g/=BASE;
	return c;
}
BIG operator*(const BIG& a,const BIG& b){
	BIG c;
	c.f=a.f*b.f;
	c.s=a.s+b.s;
	for(int i=1;i<=a.s;i++) {
		int j,g;
		for(g=0,j=1;j<=b.s;j++){
			c.a[i+j-1]+=a.a[i]*b.a[j]+g;
			g=c.a[i+j-1]/BASE;
			c.a[i+j-1]%=BASE;
		}
		c.a[i+b.s]+=g;
	}
	while(c.s>1&&!c.a[c.s]) c.s--;
	return c;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	BIG a(s1),b(s2);
	cout<<(a*b);
}
