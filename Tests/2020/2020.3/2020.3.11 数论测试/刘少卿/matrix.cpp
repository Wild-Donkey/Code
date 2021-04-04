#include<iostream>
#include<cstdio>
using namespace std;
int py[10000002];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	ios_base::sync_with_stdio(false);
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
	n--;m--;
	int l=min(n,m);
	for(int i=l;i>=2;i--)
	{
		py[i]=(n/i)*(m/i);
		for(int j=2*i;j<=l;j+=i)
		py[i]-=py[j];
		ans-=py[i];
	}
	cout<<ans+2;
}

