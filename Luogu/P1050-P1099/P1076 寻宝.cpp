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
	for(int i=1;i<=N;i++)//���� 
	{
		for(int j=0;j<M;j++)//���㿪ʼ��� 
		{
			scanf("%d%d",&Str[i][j],&S[i][j]);
			if(Str[i][j])//�ü���������ÿ����¥�ݷ����� 
				Cnt[i]++;
		}
	}
	scanf("%d",&At);
	while(Hg<=N)//��һ¥����¥ 
	{
		Sum+=S[Hg][At];
		int i=-1;//i�Ǵ�At�������ķ�������
		//cout<<At<<S[Hg][At]<<endl; 
		while(S[Hg][At])
		{
			if(Str[Hg][(At+(++i))%M])//�ߵ���¥�ݵķ��� 
				S[Hg][At]--; 
		}
		At=(At+i)%M;
		//cout<<At<<"	"<<i<<endl;
		Hg++;//����һ��¥ 
	}
	printf("%d\n",Sum%20123);//���ģһ�£���� 
	return 0;
}
