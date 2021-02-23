#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct hd
{
	int start,end;
}a[1005];
int n,at=0x7fffffff,ans=0;
bool cmp(hd x,hd y)
{
	return x.start<y.start;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].start>>a[i].end;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		if(at>=a[i].end)
		{
			at=a[i].start;
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
