#include<bits/stdc++.h>  
#define ll long long  
using namespace std;  
int f[20000],v[20000],a[211],b[211];  
int main()  
{  
    lll;  
    ints,t,m;  
    cin>>l;  
    cin>>s>>t>>m;  
    memset(f,0x3f,sizeof(f));  
    memset(v,0,sizeof(v));  
    a[0]=0;  
    for(int i=1;i<=m;i++)  
        cin>>a[i];  
    a[m+1]=l;  
    sort(a,a+m+2);  
    b[0]=0;  
    intcnt=0;  
    for(int i=1;i<=m+1;i++)  
    {  
       if(a[i]-a[i-1]>=t)  
           cnt+=(a[i]-a[i-1])%t+t;   //这里一定要在取模后加t，否则会WA；  
       elsecnt+=a[i]-a[i-1];  
       v[cnt]=1;  //表示此处有石子；  
    }  
    v[cnt]=0,v[0]=0;  
    f[0]=0;  
    for(int i=1;i<=cnt+t-1;i++)  
    {  
       for(int j=s;j<=t;j++)  
           if(i-j>=0) f[i]=min(f[i],f[i-j]+v[i]);  
    }  
    intans=2100000000;  
    for(int i=cnt;i<=cnt+t-1;i++)   //终点可能的范围； 
        ans=min(f[i],ans);  
    cout<<ans;  
    return0;  
}
