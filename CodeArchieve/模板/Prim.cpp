#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using std::sort;
using std::swap;
using std::min;
const int MAXV=5010,INF=1<<30;
double inline sqr(double a){return a*a;}
struct P{double x,y;}p[MAXV];
double inline dis(P& a,P& b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
int n;
double ans,dv[MAXV];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++) dv[i]=dis(p[1],p[i]);
	dv[1]=INF;
	int j=1;
	for(int tot=2;tot<=n;tot++){
		for(int i=1;i<=n;i++) {
			if(dv[j]>dv[i]) j=i;
		}
		ans+=dv[j];
		dv[j]=INF;
		for(int i=1;i<=n;i++) if(dv[i]!=INF) dv[i]=min(dv[i],dis(p[i],p[j]));
	}
	printf("%.2lf",ans);
}
