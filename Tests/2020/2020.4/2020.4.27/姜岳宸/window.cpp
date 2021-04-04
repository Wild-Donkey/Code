#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int a[1000005];

int n,k;
int maxn[1000005],minn[1000005];
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=k;i<=n;i++)
	{
		priority_queue< int,vector<int>,greater<int> > q1;
		priority_queue< int,vector<int>,less<int> > q2;
//		cout<<"Range:"<<i<<"~"<<i-k+1<<":";
		for(int j=i;j>i-k;j--)
		{
			q1.push(a[j]);
			q2.push(a[j]);
		}
//		cout<<"min:"<<q1.top()<<" max:"<<q2.top()<<endl;
		minn[i-k+1]=q1.top();
		maxn[i-k+1]=q2.top();
	}
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<minn[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<maxn[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

