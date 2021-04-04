#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,a,b;
	int ans=0;
	cin>>n>>m;
	a=n-2;
	if(a%2==1) a+=1;
	b=(m-2)/2;
	ans=ans+a*b;
	ans=ans+n+m-1; 
	while(ans>19268017)
	 ans=ans-19268017;
	cout<<ans;
	return 0;
}
