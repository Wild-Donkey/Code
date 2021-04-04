#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stout);
	
	int a[100000001],n,m,ans=0;
	
	scanf("%d%d",&n,&m);
	
	if(n==0&&m==0)
	{
		printf("0\n");
		return 0;
	}
	
	if(n==0||m==0)
	{
		printf("1\n");
		return 0;
	}
	
	ans=(n-1)*(m-1);
	
	n--;
	m--;
	
	for(int i=2;i<=min(n,m);i++)
	{
		a[i]=(n/i)*(m/i);
		for(int j=2*i;j<=min(n,m);j+=i)
		{
			a[i]-=a[j];
		}
		
		ans-=a[i];
	}
	
	printf("%d",ans+2);
}
