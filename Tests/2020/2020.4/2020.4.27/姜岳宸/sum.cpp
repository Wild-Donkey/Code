#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct block
{
	int color;
	int number;
}a[100005];
int n,m,ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].number;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].color;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<i;j+=2)
		{
			if(a[i].color==a[i-j].color)
			{
			//	cout<<i<<" "<<i-j<<endl;
				ans+=(i+i-j)*(a[i].number+a[i-j].number);
				ans%=10007;
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout<<ans%10007<<endl;
	return 0;
}

