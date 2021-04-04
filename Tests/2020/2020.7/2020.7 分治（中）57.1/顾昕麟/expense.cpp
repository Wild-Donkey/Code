//见识一下O(N^N)的算法(/xyx) 
#include<cstdio>
#include<algorithm>
#define N 100010
#define IAKIOI 0
using namespace std;
int n,m,it,day[N],way[N],qwq[N];
void fre()
{
	freopen("expense.in","r",stdin);
	freopen("enpense.out","w",stdout);
}
void dfs(int x)
{
	if(x==m)
	{
		int maxn=0,ans=0;
		for(int i=0;i<n;i++)
		{			
			if(way[i]==1) ans=0;
			ans+=day[i];
			if(ans>maxn) maxn=ans;
		}
		qwq[it]=maxn;
		it++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(way[i]!=1)
		{
			way[i]=1;
			x++;
			dfs(x);
			way[i]=0;
			x--;
		}
	}
}
int main()
{
	fre();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&day[i]);
	dfs(0);
	sort(qwq,qwq+N);
	for(int i=0;i<N;i++)
	{
		if(qwq[i]!=0)
		{
			printf("%d ",qwq[i]);
			break;
		}
	}
	return IAKIOI;
}
/*
7 5
200 300 300 200 500 221 420
*/
