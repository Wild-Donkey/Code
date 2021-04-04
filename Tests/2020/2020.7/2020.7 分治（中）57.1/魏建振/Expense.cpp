#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
long long n,l,r,m,a[100100],sum,mid,she;
int check(long long size)
{
	int zu=1;she=size;
	for(int i=1;i<=n;i++)
	if(she>=a[i]) she-=a[i];
	else {
		zu++,she=size-a[i];
	}
	return zu<=m;
}
int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	printf("%d",l);
	return 0;
}
