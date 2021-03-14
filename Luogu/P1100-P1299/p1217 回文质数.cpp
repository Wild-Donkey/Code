#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdio>
using namespace std;
int a[5];
struct shuzi
{
	int a[10];
	int wei=length(a);
}; 
bool zhi(int suop)//判断质数 
{
	for(int i=2;i<=sqrt(suop);i++)
		if(suop%i==0)
			return false;
	return true;
}
int len(int zh)//位数 
{
	int ans=1,zhi;
	while(zhi>=10) 
	{
		zhi/=10;
		ans++;
	}
	return 0;
}
int shu(shuzi faq)//shuzi转int 
{
	int ans;
	for(int i=0;i<=faq.wei;i++)
        ans=ans*10+faq.a[i];
}
int tiq(shuzi zho)//生成回文数 
{
	for(int i=1;i<=zho.wei-1;i++)
	{
		zho.a[i+zho.wei]=zho.a[zho.wei-i];
	}
	zho.wei=zho.wei*2-1;
}
int main()
{
	int i,l,r,faq;
	cin>>l>>r;
	int ll,lr;
	ll=len(ll);
	lr=len(lr);
	lr=min(lr,8);
    if(ll<=2)
	{
		if(ll==1)
		{
			if(l<=5&&r>=5)cout<<5<<endl;
	 		if(l<=7&&r>=7)cout<<7<<endl;
		}
		if(l<=11&&r>=11)cout<<11<<endl;
    }
	int(i=max(ll,3);i<=lr;i++)
	{
		if(i%2==0)
			continue;
		
	}
	return 0;
}
