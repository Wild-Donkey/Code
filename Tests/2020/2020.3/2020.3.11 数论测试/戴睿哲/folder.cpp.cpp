#include<iostream>
using namespace std;
const int n=1000000;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	long long a,b,c,d,e,f;
	cin>>a>>b>>c;
	for(int i=1;i<=n;i++)
	{
		f=a*i;
		e=f%b;
		if(e==c)
		{
			cout<<"YE5"<<endl;
			cout<<f/a;
			return 0;
		}

	}
	cout<<"N0"<<endl;
			cout<<0;
	
	return 0;
}
