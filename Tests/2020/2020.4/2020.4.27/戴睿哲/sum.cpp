#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define r register int
struct f
{
   int num,col;
}a[200002];

int read()
{
    int x=0; 
	char c=getchar();
    while(c>'9'&&c<'0')
	c=getchar();
    while(c<='9'&&c>='0')
	{x=x*10+c-'0'; c=getchar();}
    return x;
}
int n,m;
long long ans=0;



int main()
{   
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    n=read(); 
    m=read();
    for(r i=1;i<=n;++i)a[i].num=read();
    for(r i=1;i<=n;++i)a[i].col=read();
    for(r i=1;i<=n;++i)
        for(r j=i+1;j<=n;++j)
            if(a[i].col==a[2*j-i].col)
                ans=(ans+2*j*(a[i].num+a[2*j-i].num))%10007;
    printf("%lld",ans);
    return 0;
}
