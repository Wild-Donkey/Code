#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y,i;
int main()
{
	cin>>n;
	int a[n][4];
	for(i=1;i<=n;i++)
	{
		cin>>a[i][0];
		cin>>a[i][1];
		cin>>a[i][2];
		a[i][2]+=a[i][0];
		cin>>a[i][3];
		a[i][3]+=a[i][1];
	}
	cin>>x>>y;
	for(i=n;i>=1;i--)
	{
		if((a[i][0]<=x)&&(a[i][2]>=x))
			if((a[i][1]<=y)&&(a[i][3]>=y))
				break;
	}
	if(i==0)
	{
		cout<<-1;
		return 0;
	}
	cout<<i;
	return 0;
}
