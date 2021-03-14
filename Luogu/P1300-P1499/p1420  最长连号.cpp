#include<iostream>
using namespace std;
int n,ans,a[10005],b=1;
int main()
{
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[i-1]+1)
			b++;
		else
		{
			ans=max(b,ans);
			b=1;
		}
	}
	ans=max(b,ans);
	cout<<ans;
	return 0;
}
