#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
string a[10001];
bool cmp(const string &x,const string &y)
{
	if (x.size()!=y.size()) return x.size()>y.size();
	else return x>y;
}
bool ispalnum(const string &s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--)
		if(s[i]!=s[j]) return false;
	return true;
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(ispalnum(a[i]))
		{
			cout<<a[i];
			break;
		}
	}
	return 0;
} 
