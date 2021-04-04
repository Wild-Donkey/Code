#include<iostream>
#include<cstdio>

using namespace std;

inline int power_fast(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=a*ans;
		a=a*a;
		b>>=1;
	}
	return ans;
}

int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	int x,n;
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	
	cin>>x>>n;
	
//	cout<<2;
	cout<<power_fast(x,n);
}
