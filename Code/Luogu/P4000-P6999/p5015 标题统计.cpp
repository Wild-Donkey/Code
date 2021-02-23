#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
string a;
int ans=0;
int main()
{
	for(int i=0;i<=4;i++)
	{
		a[i]=getchar();
		if((a[i]<='9'&&a[i]>='0')||(a[i]<='z'&&a[i]>='a')||(a[i]<='Z'&&a[i]>='A'))
			ans++;
	}
	cout<<ans; 
	 return 0;
}
