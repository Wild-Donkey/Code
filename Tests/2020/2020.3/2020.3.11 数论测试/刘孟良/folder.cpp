#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

long long gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

long long a,b,c;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		long long u=exgcd(b,a%b,y,x);
		y-=x*(a/b);
		return u;
	}
}

int main()
{
	freopen("folder.in","r",stdin);
	freopen("folader.out","w",stdout);
	cin>>a>>b>>c;
	if((c%gcd(a,b))!=0)
	{
		cout<<"N0"<<endl;
		cout<<0<<endl;
		return 0;
	}
	// 对于一般的二元一次不定方程：ax+by=c.
	//两边同时除以gcd(a,b).只有c/gcd(a,b)c才能保证右边是整数.
	//则题可转化为：ax-by=c。
	long long x=0,y=0;
	long long p=exgcd(a,-b,x,y);
	long long a1=abs(b/p),a2=abs(a/p);
	x=x*(c/p);
	y=y*(c/p);
	if(x<0||y<0)
	{
		long long s1=abs(x/a1),s2=abs(y/a2);
		if(s1<s2)
			s1=s2;
		x+=(s1+1)*a1;
		y+=(s1+1)*a2;
	}
	else
	{
		long long s1=abs(x/a1),s2=abs(y/a2);
		if(s1>s2)
			s1=s2;
		x-=s1*a1;
		y-=s1*a2;
	}
	cout<<"YE5"<<endl;
	cout<<x<<endl;
}
