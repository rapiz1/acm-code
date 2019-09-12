 /* AC-Automaton
多文本的多模式串匹配 
统计匹配次数 
*/ 
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using std::queue;
const int MAXL=1e7,MAXW=1e4,SETSIZE=26;
int w,n,realw,gans[MAXW];
int sz;
char buf[MAXL],mod[MAXW][100];
struct NODE{
	char data;
	int ch[70],cnt,fail;
	bool rec[MAXW];
	void merge(NODE& o){
		for(int i=1;i<=realw;i++) rec[i]=rec[i]||o.rec[i];
	}
}trie[100];
void in(char* str,int strid){
	int pos=0;
	while(*str){
		int chid=*str-'a'+1;
		if(trie[pos].ch[chid]) pos=trie[pos].ch[chid];
		else pos=trie[pos].ch[chid]=++sz,trie[sz].data=*str;
		str++;
	}
	trie[pos].cnt++;
	trie[pos].rec[strid]=1;
}
void build_trie(){
	queue<int> q;
	int now=0,p;
	trie[now].fail=0;
	for(int i=1;i<=SETSIZE;i++) if(trie[now].ch[i]){
		q.push(trie[now].ch[i]);
		trie[trie[now].ch[i]].fail=0;
	}
	while(!q.empty()){
		now=q.front();q.pop();
		for(int i=1;i<=SETSIZE;i++) if(trie[now].ch[i]){
			p=trie[now].fail;
			while(!trie[p].ch[i]&&p) p=trie[p].fail;
			if(trie[now].ch[i]) trie[trie[now].ch[i]].fail=trie[p].ch[i],trie[trie[now].ch[i]].cnt+=trie[trie[p].ch[i]].cnt,trie[trie[now].ch[i]].merge(trie[trie[p].ch[i]]);
			else trie[trie[now].ch[i]].fail=0;
			q.push(trie[now].ch[i]);
		}
	}
}
int match(char* s){
	int len=strlen(s),ans=0,now=0;
	for(int i=0;i<len;i++){
		int chid=s[i]-'a'+1;
		while(now&&!trie[now].ch[chid]) now=trie[now].fail;
		if(trie[now].ch[chid]) now=trie[now].ch[chid];
		ans+=trie[now].cnt;
		for(int i=1;i<=realw;i++) gans[i]+=trie[now].rec[i]; 
	}
	return ans;
}
int main(){
	freopen("ACautomata.in","r",stdin);
	freopen("ACautomata.out","w",stdout);
	scanf("%d",&w);
	for(int i=1;i<=w;i++) scanf("%s",mod[i]),in(mod[i],i);
	realw=w;
	build_trie();
	scanf("%s",buf);
	match(buf);
	for(int i=1;i<=realw;i++) printf("%s %d\n",mod[i],gans[i]);
	//printf("%s",article+1);
}
