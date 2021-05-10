#include<iostream>
#include<cstdio>
using namespace std;
int a,b,Max=1001,d;
bool c=false;
int main()
{
	cin>>a>>b;
	for(int k=1;k<=Max;k++)
	{
		for(int i=0;i<=Max;i++)
			for(int j=0;j<=Max;j++)
				if(a*i+b*j==k)
					c=true;
		if(!c)
			d=k;
		c=false;
	}
	cout<<d;
	return 0; 
} 
