#include<iostream>
#include<cstdio>
using namespace std;
int S[10005][105],M,N,At,Hg=1,Cnt[10005]={0};
long long Sum=0;
bool Str[10005][105];
int main()
{
//	freopen("faq.in","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)//层数 
	{
		for(int j=0;j<M;j++)//从零开始编号 
		{
			scanf("%d%d",&Str[i][j],&S[i][j]);
			if(Str[i][j])//用计数器存下每层有楼梯房间数 
				Cnt[i]++;
		}
	}
	scanf("%d",&At);
	while(Hg<=N)//从一楼到顶楼 
	{
		Sum+=S[Hg][At];
		int i=-1;//i是从At往后数的房间数量
		//cout<<At<<S[Hg][At]<<endl; 
		while(S[Hg][At])
		{
			if(Str[Hg][(At+(++i))%M])//走到有楼梯的房间 
				S[Hg][At]--; 
		}
		At=(At+i)%M;
		//cout<<At<<"	"<<i<<endl;
		Hg++;//更上一层楼 
	}
	printf("%d\n",Sum%20123);//最后模一下，输出 
	return 0;
}
