#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c;
int gcd(int p,int q)
{
	p=abs(p);
	q=abs(q);
	return (p%q==0)?q:gcd(q,p%q);
}
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	cin>>a>>b>>c;
	if(c%gcd(a,b)!=0)
	{
		cout<<"N0"<<endl<<0;
	}
	else
	{
		cout<<"YE5"<<endl;
		for(int x=1;;x++)
		{
			if((a*x-c)%b==0)
			{
				cout<<x<<endl;
				break;
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

