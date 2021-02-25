#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
string s;
int main()
{
	freopen("copycat.in","r",stdin);
	freopen("copycat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		cout<<s<<endl;
	}
	return 0;
}
