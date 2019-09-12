namespace IStream{  
    const int L=1<<15;  
    char buffer[L],*S,*T;  
    inline char Get_Char()  
    {  
        if(S==T)  
        {  
            T=(S=buffer)+fread(buffer,1,L,stdin);  
            if(S==T) return EOF;  
        }  
        return *S++;  
    }  
    inline int gi()  
    {  
        char c;  
        int re=0;  
        for(c=Get_Char();c<'0'||c>'9';c=Get_Char());  
        while(c>='0'&&c<='9')  
            re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();  
        return re;  
    }  
}
namespace IO{
	char buf[1<<15],*fs,*ft;
	inline char gc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
	inline int gi(){
		int x=0,rev=0,ch=gc();
		while(ch<'0'||ch>'9'){if(ch=='-')rev=1;ch=gc();}
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=gc();}
		return rev?-x:x;
	}
}
