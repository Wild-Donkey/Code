#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define Mod 10007
#define N 100007
long long ans,sum[2][N],color[N],number[N];
int vis[2][N];
using namespace std;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>number[i];
		number[i]%=Mod;
	}
	for(int j=1;j<=n;j++)
	{
		cin>>color[j];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i%2][color[i]]+=number[i];
        sum[i%2][color[i]]%=Mod;
        vis[i%2][color[i]]++;
	}
	
	for(int i=1;i<=n;i++)
{
	ans+=((i*(vis[i%2][color[i]]-2)*number[i])%Mod+(sum[i%2][color[i]]*i))%Mod;
	ans%=Mod;
}

cout<<ans;
return 0;	
 } 
