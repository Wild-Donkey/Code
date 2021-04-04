#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[100000];
bool check(int x)
{
	int k=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]>x)
		{
			sum=a[i];
			k++;
		}
		else sum+=a[i];
	}
	if(k<=m) return true;
	return false;
}

int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ans=0,l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)==true)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	} 
	printf("%d\n",ans);
	return 0;
}
