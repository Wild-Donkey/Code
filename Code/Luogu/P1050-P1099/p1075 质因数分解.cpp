#include<iostream>
#include<cmath>
using namespace std;  
int a,s;
int main()  
{
	cin>>a;
	s=sqrt(double(a));
	for(int i=2;i<=s;i++)
	{	
		if(a%i==0)
			a/=i;
	} 
	cout<<a;
    return 0;  
}
