#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long a,b,c;


int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	cout.tie(NULL);
	cin>>a>>b>>c;
	unsigned long long x;
	if(c>=b) {
		cout<<"NO"<<'\n'<<0;return 0;
	}
	
	for(unsigned long long i=1;;i++)
	{
		x=i*a;
		if(x%b==c) {cout<<"YES";cout<<'\n'<<x/a;
		return 0;}
	}

 } 
