#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long n,k,i,j; 
long long a[1000100],minn[1000100],maxn[1000100];
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	memset(minn,0x3f,sizeof(minn));
	memset(maxn,-0x3f,sizeof(maxn));
	cin>>n>>k;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	for(i=1;i<=n-k+1;i++)
	{
		for(j=i;j<=i+k-1;j++)
		{
			minn[i]=min(minn[i],a[j]);
			maxn[i]=max(maxn[i],a[j]);
		}
	}
	for(i=1;i<=n-k+1;i++)
	cout<<minn[i]<<" ";
	cout<<endl;
	for(i=1;i<=n-k+1;i++)
	cout<<maxn[i]<<" ";
	return 0;
}

