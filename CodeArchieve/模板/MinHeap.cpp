//小根堆
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int s[MAXN],cnt,n;
//下标从1开始 
void up(int k){
	while(k/2!=0&&s[k/2]>s[k]) swap(s[k/2],s[k]),k/=2;
}
//迭代版 
/*void down(int k){
	int c=k,l=2*c,t=s[k];
	while(c<=cnt){
		if(l+1<=cnt&&s[l]>s[l+1]) l++;
		if(t<=s[l]) break;
		s[c]=s[l];
		c=l;
		l*=2;
	}
}*/
//迭代版v2
/*void down(int k) {
	int l=2*k,t=s[k];
	while(k<=cnt){
		if(l+1<=cnt&&s[l]>s[l+1]) l++;
		if(t<=s[l]) break;
		s[k]=s[l];
		k=l;
		l*=2;
	}
}*/
//递归版
void down(int k){
	if(k>=cnt) return;
	int l=2*k;
	if(l+1<=cnt&&s[l]>s[l+1]) l++;
	if(s[k]<=s[l]) return;
	else s[k]=s[l],down(l);
}
void in(int t) {
	s[++cnt]=t;
	up(cnt);
}
void re(int k){
	s[k]=s[cnt];
	down(k);
	cnt--;
}
int main() {
	int t;
	cin>>n;
	for(int i=0;i<n;i++) cin>>t,in(t);
	cout<<s[1];
	re(1);
	cout<<endl<<s[1];
}
