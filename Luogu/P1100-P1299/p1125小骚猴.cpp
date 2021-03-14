#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int b[26]={0},l,maxn=-0x7fffffff,minn=0x7fffffff,ans=0;
int zs[1000]={}
string a;
bool zhi(int f)//≈–∂œ÷  ˝ 
{
	
	for(int i=2;i<=sqrt(f);i++)
		if(f%i==0)
			return false;
		else
			return true;
}
int main()
{
	cin>>a;
	l=a.length();
	for(int i=1;i<=l;i++)
		b[a[i]-'a']++;
	for(int i=0;i<=25;i++)
	{
		maxn=max(maxn,b[i]);
		minn=min(minn,b[i]);
	}
	ans=maxn-minn;
	if(zhi(ans))
		cout<<"Lucky Word"<<endl<<ans;
	else
		cout<<"No answer"<<endl<<0;
	return 0;
}
