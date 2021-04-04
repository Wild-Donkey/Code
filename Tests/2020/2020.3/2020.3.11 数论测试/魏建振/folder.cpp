#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("folder.in","r",stdin);
    freopen("folder.out","w",stdout);
	long long a,b,c,d;
	cin>>a>>b>>c;
	d=a;
	if(c>=b)
	cout<<"N0"<<endl<<"0";
	else
	{for(long long i=1;;i++)
	{d*=i;
	if(d%b==c)
	break;
	else d/=i;
    }
    cout<<"YE5"<<endl<<d/a;
    }
    return 0;
}
