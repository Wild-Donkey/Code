#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstring>
using namespace std;

long long n,m,answer;
long long a[100001];
long long l=1,r,mid;

bool judge(long long x)
{
	long long sum=0;
	long long ans=1;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]+sum>x)
		{
			sum=0;
			ans++;
		}
		
		sum+=a[i];
	}
	
	if(ans>m) return false;
	else return true;
}

int main(void)
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}
	
	r+=10;
	
	while(l<r)
	{
		mid=l+(r-l)/2;
		
		if(judge(mid)==0)
		{
			l=mid+1;
		}
		else r=mid;
	}
	
	printf("%lld",r);
	
	return 0;
}
