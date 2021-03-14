#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y,logn;
int main()
{
	cin>>n>>m;//n个数据,m次询问 
	int ans[m],log[n+5],f[n+5][17];	
	for(int i=1;i<=n;i++)
		cin>>f[i][0];//读入 
	log[0]=-1;
	for(int i=1;i<=n;i++)
	{
		log[i]=log[i>>1]+1;//预处理log[n] 
	}
	logn=log[n];
	for(int i=1;i<=logn;i++)//预处理f[n][logn],i是当前搞的log值 
		for(int j=0;j+(1<<i)-1<=n;j++)//j+2^i-1<=n(保证区间不溢出) 
			f[j][i]=max(f[
			-);//把该区间分为左右两区间
	for(int i=0;i<m;i++)//询问m次 
	{
		cin>>x>>y;
		int s=log[y-x+1];
		cout<<max(f[x][s],f[y-(1<<s)+1][s])<<endl;
	}
	return 0;
}
