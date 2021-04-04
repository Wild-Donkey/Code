#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1000010],maxx[1000010],minn[1000010],zkw[1000010],n,k;
long long cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		zkw[i]=a[i];
	}
	for(int i=1;i<=n-k+1;++i)
	{
		sort(zkw+i,zkw+i+k,cmp);
		maxx[i]=zkw[i];
		minn[i]=zkw[i+k-1];
		for(int j=i;j<=i+k-1;++j)
		{
			zkw[j]=a[j];
		}
	}
	for(int i=1;i<=n-k+1;++i)
	{
		printf("%lld ",minn[i]);
	}
	printf("\n");
	for(int i=1;i<=n-k+1;++i)
	{
		printf("%lld ",maxx[i]);
	}
	return 0;
}
