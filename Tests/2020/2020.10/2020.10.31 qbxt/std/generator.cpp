#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int left[3000010],right[3000010],que[3000010],h,t;  
int n,ans;  
inline int read(){
    char ch=getchar();  
    int opt=1,x=0;  
    while(!(ch>='0'&&ch<='9')) if(ch=='-') opt=-1,ch=getchar();  
    while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();  
    return (x*opt);   
}  
int main(){  
    int i,j;  
    n=read();  
    for(i=1;i<=n;++i){  
        int x=read(),y=read();  
        left[i]=x; right[i]=y;  
    }
    h=1; ans=1;  
    for(i=1;i<=n;++i){  
        while(h<=t&&left[que[t]]<=left[i]) --t;  
        que[++t]=i;  
        while(h<=t&&left[que[h]]>right[i]) ++h;  
        ans=max(ans,i-que[h-1]);  
    }  
    printf("%d\n",ans);  
    return 0;  
 }   
