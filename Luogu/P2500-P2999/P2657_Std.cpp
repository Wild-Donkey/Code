#include<bits/stdc++.h>
using namespace std;
//��dp[i][j]Ϊ����Ϊi�����λ��j��windy���ĸ���
//���� dp[i][j]=sum(dp[i-1][k]) ���� abs(j-k)>=2 
int p,q,dp[15][15],a[15], A, B;
void init()
{
	for(int i=0;i<=9;i++)	dp[1][i]=1;	//0,1,2,3,4...9������windy�� 
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(abs(j-k)>=2)	dp[i][j]+=dp[i-1][k]; 
			}
		}
	}//�ӵڶ�λ��ʼ ÿ��ö�����λj ���ҵ�k ʹ��j-k>=2 
}
int work(int x)	//����<=x��windy�� 
{
	memset(a,0,sizeof(a));
	int len=0,ans=0;
	while(x)
	{
		a[++len]=x%10;
		x/=10;
	}
	//��Ϊ������� ����len-1λ��windy�� �ض�������������� 
	for(int i=1;i<=len-1;i++)
	{
		for(int j=1;j<=9;j++)
		{
			ans+=dp[i][j];
		} 
	}
	//Ȼ����lenλ �����λ<a[len]��windy�� Ҳ������������ 
	for(int i=1;i<a[len];i++)
	{
		ans+=dp[len][i];
	} 
	//������lenλ ���λ��ԭ����ͬ�� ���Ѹ��һ���� 
	for(int i=len-1;i>=1;i--)
    {
    	//i�����λ��ʼö�� 
        for(int j=0;j<=a[i]-1;j++)
		   {
		   	//j��iλ�ϵ��� 
		   		if(abs(j-a[i+1])>=2)	ans+=dp[i][j]; //�жϺ���һλ(i+1)���2����
				   //����� ans���ۼ� 
		   } 
		if(abs(a[i+1]-a[i])<2)       break;
      //  if(i==1)   ans+=1;
    }
	return ans;
}
int main()
{
  freopen("P2657.in", "r", stdin);
  freopen("std.out", "w", stdout);
	init();
	cin>>p>>q;
	A = work(p);
	B = work(q + 1);
	printf("%u %u %u\n", A, B, B - A);
//	cout<<work(q+1)-work(p)<<endl;
	return 0;
}
