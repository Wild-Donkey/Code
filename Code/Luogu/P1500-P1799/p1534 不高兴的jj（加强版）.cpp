#include<iostream>
using namespace std;
int n,a[3005],b[3005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]+=b[i];
	}
	b[0]=0;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i]-8;
	for(int i=1;i<=n;i++)
		b[0]+=b[i];
	cout<<b[0];
	return 0;
}
