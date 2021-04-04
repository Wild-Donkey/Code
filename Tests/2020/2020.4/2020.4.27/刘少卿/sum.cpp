#include<iostream>
#include<cstdio>
#include<algorithm>

const int  py=1e5+5;

int num[py],color[py];
int sum[py][3],spite[py][3];
int ans;

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		std::cin>>num[i];
	
	for(int i=1;i<=n;i++)
	{
		std::cin>>color[i];
		spite[color[i]][i%2]++;
		sum[color[i]][i%2] = (sum[color[i]][i%2] + num[i]) % 10007;
	}
	
	for(int i=1;i<=n;i++)
	ans+=(i * ((spite[color[i]][i % 2]-2) * num[i] % 10007 + sum[color[i]][i%2])) % 10007,ans%=10007; 
	
	std::cout<<ans;
 } 
