#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int a[100003];
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	double d=1.0*n/m;
	double c=ceil(d);
	int geju=c;
	int sum;
	int mingeju;
	int meigeju=999999;
	for(int i=1;i<=n-geju-1;i++)
	{	
		
		sum=a[i];
		while(geju>i)
		{
			
			sum+=a[i+geju];
			geju--;
		}
		mingeju=min(sum,meigeju);
	}
	int ans;
	for(int i=1;i<c;i++)
	{
		ans=a[n];
		ans+=a[n-i];
	}
	if(ans<mingeju)
	{
		cout<<ans;
	}
	else
	cout<<mingeju;
	return 0;
	
//	7 5 200 300 300 200 500 221 420
}
