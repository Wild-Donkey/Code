#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,a[51];
	string s;
	cin>>n;
	n%=26;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		a[i]=(s[i]-'a'+n)%26+'a';
		s[i]=a[i];
	}
	cout<<s;
	return 0;
}
