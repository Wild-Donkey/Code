#include<iostream>
#include<cstdio>
#include<algorithm>
int a[100000],b[100000];
using namespace std;
int main()
{
	freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	int n,m,i,j=1,s=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	cin>>b[i];
	for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    {
	if(b[i]==b[2*j-i])
    s=s+2*j*(a[i]+a[2*j-i]);
    s%=10007;
	}
	cout<<s%10007; 
	return 0;
}
