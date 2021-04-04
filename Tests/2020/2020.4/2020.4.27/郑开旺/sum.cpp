#include<iostream>
#include<cstdio>
using namespace std;
struct zkw{
	long long coler;
	long long number;
};
zkw a[100010];
long long n,m;
long long ans=0;
const int w=10007;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i].number);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i].coler);
	}
	for(int i=1;i<=n-2;++i)
	{
		for(int j=i+2;j<=n;j+=2)
		{
			if(a[i].coler==a[j].coler)
			{
				ans+=(i+j)%w*(a[i].number+a[j].number)%w;
				ans%=w;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
