#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long n,m,group,sum,l,r,mid,i;
int a[100010];
bool vailu(int size)
{
	int rest=size;
	group=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>size)
		return false;
		if(rest>=a[i])
		rest-=a[i];
		else if(rest<a[i])
		{
			group++;
			rest=size;
		}
	}
	return group<=m;
}
int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	//cout<<sum<<endl;
	l=0,r=sum;
	while(l<r)
	{
		mid=(l+r)/2;
		if(vailu(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
/*7 5
200 300 300 200 500 221 420*/

