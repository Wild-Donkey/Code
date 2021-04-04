#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	long long s,n,a,b,c;
	cin>>a>>b>>c;
	for(n=1;n<=1000000;++n)
	{
		s=n*a;
		if((s-c)%b==0)		
		{
			cout<<"YE5"<<endl<<n;
			return 0;
		}
	}
	cout<<"N0"<<endl<<"0";
	return 0;
}
