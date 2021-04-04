#include<iostream>
#include<cstdio>

using namespace std;

long long m,n,ans,a[10000001];

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
	if(m==1&&n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	ans=(n-1)*(m-1);
	n--,m--;
	for(int i=n;i>=2;i--)
	{
		a[i]=(n/i)*(m/i);
		for(int j=2*i;j<=n;j+=i)
			a[i]-=a[j];
		ans-=a[i];
	}
	cout<<ans+2;
	return 0;
}
