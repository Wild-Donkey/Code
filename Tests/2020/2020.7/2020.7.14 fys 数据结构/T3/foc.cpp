#include<iostream>
#include<cstdio>

using namespace std;

int a[23333333];

#define INF -1<<30

int main()
{
	int n,m;
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	cin>>m;
	int py=n;
	
	for(int i=1;i<=m;i++)
	{
		int x;
		
		cin>>x;
		
		if(x == 0)
		{
			int maxn=0;
			for(int i=1;i<=py;i++)
			{
				maxn=max(maxn,a[i]);
			}
			cout<<maxn<<endl;
		}
		int g;
		if(x == 1)
		{
			cin>>g;
			a[++py]=g;
		}
		
		if(x == 2)
		{
			cin>>g;
			a[g]=INF;
		}
	}
}
