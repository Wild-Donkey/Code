#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
bool if_canback(int n,int m)
{
	int j=0;
	while(n)
	{
		n/=10;
		j++;
	}
	if(n!=m)return false;
	return true;
}
long long pow10(int x)
{
    long long ans=1;
    for(int i=1;i<=x;++i)ans*=10;return ans;
}

int s[100003],a[100003],cnt,tmp;

int main()
{
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	int k,m;
	cin>>k>>m;
	int cur=k;
	while(cur)
	{
		int y=cur%10;
		s[++cnt]=y;
		cur/=10;
	}
	if(k%10==0)
	{
		if(if_canback)
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
	    for(int i=1;i<=cnt;++i)
	    {
			 a[i]=s[cnt-i+1];
		}
 
        int kk=1;long long pre=0;
   for(int i=1;i<=cnt;++i)
   {
    pre=1ll*pre*10+a[i];
    tmp+=pre-pow10(i-1)+1;
   }
   if(tmp>m)cout<<0<<endl;
   else if(tmp==m)cout<<k<<endl;
   else{    
   kk=1;m-=tmp;
   long long num=1ll*pre*10-pow10(cnt+kk-1);
    while(num<m)
    {
    m-=num;num*=10;kk++;
    }
       cout<<pow10(kk+cnt-1)+m-1;
    } 
	}
	
	return 0;
}

