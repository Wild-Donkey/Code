#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[30],n;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	f[0]=1;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++)
	{
		int sum=0,p=i-1;
		for(int j=0;j<=p;j++)
		{
			sum+=f[j]*f[p-j];
			sum%=19260817;
		}
		f[i]=sum%19260817;
	}
	cout<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

