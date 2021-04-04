#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int n,m,x,y,z,number[100001],color[100001],ans=0;
	
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	cin>>number[i];
	
	for(int i=1;i<=n;i++)
	cin>>color[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n-i;j+=2)
		{
			x=i;
			z=x+j;
			
			if(color[x]==color[z])
			ans+=((x+z)%10007)*((number[x]+number[z])%10007)%10007;
		}
	}
	
	cout<<ans%10007;
	
	return 0;
}
