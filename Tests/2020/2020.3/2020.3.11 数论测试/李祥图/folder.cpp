#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define LL long long
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    LL r=ex_gcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

const LL maxn=1000;
LL a[maxn],m[maxn],n;

LL CRT(LL a[],LL m[],LL n) 
{
    if (n==1) 
	{
        if (m[0]>a[0]) return a[0];
        else return -1;
    }
    LL x, y, d;
    for (int i=1;i<n;i++) 
	{
        if (m[i]<=a[i]) return -1;
        d=ex_gcd(m[0],m[i],x,y);
        if ((a[i]-a[0])%d!=0) return -1; 
        LL t=m[i]/d;
        x =((a[i]-a[0])/d*x%t+t)%t;
        a[0]=x*m[0]+a[0];
        m[0]=m[0]*m[i]/d;
        a[0]=(a[0]%m[0]+m[0])%m[0];
    }
    return a[0];
}

int main ()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
   	cin>>m[1]>>m[0]>>a[0];
   	a[1]=0;
   	int n=CRT(a,m,2);
	if(n==-1) cout<<"N0"<<endl<<"";
	else 
	{
		cout<<"YE5"<<endl;	
		cout<<n/m[1];
	}
}
