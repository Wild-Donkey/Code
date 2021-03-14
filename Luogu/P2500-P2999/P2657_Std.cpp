#include<bits/stdc++.h>
using namespace std;
//设dp[i][j]为长度为i中最高位是j的windy数的个数
//方程 dp[i][j]=sum(dp[i-1][k]) 其中 abs(j-k)>=2 
int p,q,dp[15][15],a[15], A, B;
void init()
{
	for(int i=0;i<=9;i++)	dp[1][i]=1;	//0,1,2,3,4...9都属于windy数 
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(abs(j-k)>=2)	dp[i][j]+=dp[i-1][k]; 
			}
		}
	}//从第二位开始 每次枚举最高位j 并找到k 使得j-k>=2 
}
int work(int x)	//计算<=x的windy数 
{
	memset(a,0,sizeof(a));
	int len=0,ans=0;
	while(x)
	{
		a[++len]=x%10;
		x/=10;
	}
	//分为几个板块 先求len-1位的windy数 必定包含在区间里的 
	for(int i=1;i<=len-1;i++)
	{
		for(int j=1;j<=9;j++)
		{
			ans+=dp[i][j];
		} 
	}
	//然后是len位 但最高位<a[len]的windy数 也包含在区间里 
	for(int i=1;i<a[len];i++)
	{
		ans+=dp[len][i];
	} 
	//接着是len位 最高位与原数相同的 最难搞的一部分 
	for(int i=len-1;i>=1;i--)
    {
    	//i从最高位后开始枚举 
        for(int j=0;j<=a[i]-1;j++)
		   {
		   	//j是i位上的数 
		   		if(abs(j-a[i+1])>=2)	ans+=dp[i][j]; //判断和上一位(i+1)相差2以上
				   //如果是 ans就累加 
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
