#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	double s,a,b,ans;
	cin>>s>>a>>b;
	ans=s/(a+b/2+a/2)*(b/2+a/2)/b+s/(a+b/2+a/2);
	printf("%.2lf",ans);
}
