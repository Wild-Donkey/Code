#include<iostream>
#include<cstdio>
#define N 19268017
using namespace std;
int a[10000002];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1) {
		cout<<0;
		return 0;
	}
	if(n==1||m==1) {
		cout<<1;
		return 0;
	}
	int ans=(n-1)*(m-1);
	n--;
	m--;
	int l=min(n,m);
	for(int i=l;i>=2;i--)
	{
		a[i]=(n/i)*(m/i);
		for(int j=2*i;j<=l;j+=i) a[i]-=a[j];
		ans-=a[i];
	}
	ans=(ans+2)%N;
	cout<<ans;
}

