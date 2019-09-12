#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int BASE=1e4,WIDTH=4;
struct BIG{
	int s,a[110];//[1...109]存放个十百千,s指示最后元素的下标 
	BIG(){
		memset(this,0,sizeof(*this));
	}
	BIG(const string& str){
		memset(this,0,sizeof(*this));
		int t;
		for(int i=str.size();i>=0;i-=WIDTH){
			t=max(i-WIDTH,0);
			sscanf(str.substr(t,i-t).c_str(),"%d",&(this->a[++(this->s)]));
		}
	}
};
BIG operator+(const BIG& a,const BIG& b){
	BIG c;
	c.s=max(a.s,b.s);
	int g=0,i;
	for(i=1;i<=c.s;i++){
		g+=a.a[i]+b.a[i];
		c.a[i]=g%BASE;
		g/=BASE;
	}
	if(g) c.a[++c.s]=g;
	return c;
}
/*BIG operator-(BIG a,BIG b){
	BIG c;
	c.s=a.s;
	int j=0,i;
	for(int i=1;i<=c.s;i++){
		if(a.a[i]<b.a[i]) a.a[i+1]--,c.a[i]=a.a[i]+BASE-b.a[i];
		else c.a[i]=a.a[i]-b.a[i];
	}
	while(c.s>1&&c.a[c.s]==0) c.s--;
	return c;
}*/
BIG operator-(const BIG& a,const BIG& b){
	BIG c;
	c.s=a.s;
	int j=0,i;
	for(int i=1;i<=c.s;i++){
		if(a.a[i]-j<b.a[i]) c.a[i]=a.a[i]-j+BASE-b.a[i],j=1;
		else c.a[i]=a.a[i]-j-b.a[i],j=0;
	}
	while(c.s>1&&c.a[c.s]==0) c.s--;
	return c;
}
bool operator<(const BIG& a,const BIG& b){
	if(a.s<b.s) return true;
	else if(a.s>b.s) return false;
	else for(int i=a.s;i;i--) {
		if(a.a[i]<b.a[i]) return true;
		if(a.a[i]>b.a[i]) return false;
	}
	return false;
}
bool operator>(const BIG& a,const BIG& b){
	if(a.s<b.s) return false;
	else if(a.s>b.s) return true;
	else for(int i=a.s;i;i--) {
		if(a.a[i]<b.a[i]) return false;
		if(a.a[i]>b.a[i]) return true;
	}
	return false;
}
bool operator==(const BIG& a,const BIG& b){
	if(a.s!=b.s) return false;
	else for(int i=a.s;i;i--) if(a.a[i]!=b.a[i]) return false;
	return true;
}
bool operator!=(const BIG& a,const BIG& b){
	return !(a==b);
}
ostream& operator<<(ostream& out,const BIG& a){
	printf("%d",a.a[a.s]);
	for(int i=a.s-1;i;i--) printf("%04d",a.a[i]);
	return out;
}
void gcd(BIG a,BIG b,BIG& c){
	while(a!=b){
		if(a>b) a=a-b;
		if(a<b) b=b-a;
	}
	c=a;
}
int main(){
	string a,b;
	cin>>a>>b;
	BIG p(a),q(b),ans;
	gcd(p,q,ans);
	cout<<ans;
}
