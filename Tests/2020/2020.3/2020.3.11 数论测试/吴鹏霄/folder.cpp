#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long a,b,c;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>a>>b>>c;
	unsigned long long x;
	if(c>=b) 
	for(unsigned long long i=1;;i++)
	{
		x=i*a;
		if(x%b==c) 
		{
		    cout<<"YE5";
			cout<<'\n'<<x/a;
		}
		else
		cout<<"NO"<<'\n'<<0;
		return 0;
	} 
} 
