#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

long long m[1000001],a[1000001],minn[1000001],maxx[1000001];
long long n,k,x,y,p,q;

int main(void)
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
	
	cin>>n>>k;
	
	cin>>a[1];
	
	p=a[1];
	q=a[1];
	
	if(n==1)
	{
	    cout<<a[1]<<endl<<a[1]<<endl;
	    return 0;
	}
	
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(p>=a[i]) p=a[i];
		if(q<=a[i]) q=a[i];
	}
	
	for(int i=1;i<=n-k+1;i++)
	{
		x=q+1;
		y=p-1;
		
		for(int j=i;j<=i+k-1;j++)
		{
			x=min(x,a[j]);
			y=max(y,a[j]);
		}
		
		minn[i]=x;
		maxx[i]=y;
	}
	
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<minn[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<maxx[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
} 
