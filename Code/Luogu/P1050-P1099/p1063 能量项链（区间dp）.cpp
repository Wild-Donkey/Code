#include<iostream>
using namespace std;
int l[205],r[205],f[205][205]={0},ans=0,n,temp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		l[i+n]=l[i];
	}
	for(int i=1;i<=2*n-1;i++)
		r[i]=l[i+1];
	r[2*n]=l[1];
	for(int i=1;i<=2*n-1;i++)
		f[i][i]=0;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=2*n-i;j++)
		{
			temp=i+j;
			for(int k=j;k<=temp-1;k++)
				f[j][temp]=max(f[j][temp],f[j][k]+f[k+1][temp]+l[j]*r[k]*r[temp]);
		}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][i+n-1]);
	cout<<ans<<endl;
	return 0;
}
