#include<cstdio>
#include<iostream>
#define N 25
using namespace std;
long long s[N],f[N];
long long n,m,k;
long long cnt=0;
long long a=1;

void get(long long x)
{
    int t=0;
    while(x)
    {
        s[++t]=x%10;
        x/=10;
        a*=10;
    }
    a/=10;
    for (int i=1;i<=t;i++)
        f[i]=s[t-i+1];
    cnt+=t-1;
    for (int i=t;i>=1;i--)
    {
        long long now=0;
        for (int j=1;j<=i;j++)
        {
            if(j!=1)
                now=now*10+f[j];
                else now=now*10+f[j]-1;
        }
        cnt+=now;
    }
}
int main()
{
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
    cin>>k>>m;
    get(k);
    if (cnt>=m||k==a&&cnt<m-1)
    {
    	cout<<0;
        return 0;
    }
    long long x=k-a,y=k;
   while(cnt<m-1) 
    {
        x*=10;
        y*=10;
        cnt+=x;
    }
    long long ans=max(k,y-(cnt-m+2));
    cout<<ans;
}
