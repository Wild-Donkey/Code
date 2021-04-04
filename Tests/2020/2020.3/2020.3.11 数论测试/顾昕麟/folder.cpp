//AJHµÄÎÄ¼þ¼Ð
#include<cstdio>
#include<iostream>
using namespace std;
long long gcd(long long x,long long y)
{
	if(x%y==0) 
	{
		return y;
	}
	return gcd(y,x%y);
}
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	long long a,b,c,num=0;
	scanf("%lld%lld%lld",&a,&b,&c);
	if (c%gcd(a,b)!=0)
	{
		cout<<"N0";
		return 0;
	}
	else
	{
		cout<<"YE5"<<endl;
		for (long long i=0;;i++)
		{
			if (((c+b*i)%a)==0)
			{
				cout<<(c+b*i)/a;
				break;
			}
		}
	}
	return 0;
} 
