#include<iostream>
using namespace std;
int ans=0;//n:剩余可分配数,m:剩余可分配位置 
void xjj(int nx,int mx,int nn,int &ans)
{
	int a=nx/mx;//当前位置最大临界
	if(mx<=2)//到达边界
	{
		int c=a+1-nn;
		ans+=c;
	}
	mx--;//枚举到下一位 
	for(int i=1;i<=a;i++)//枚举当前位置所存数字 
		xjj(nx-i,mx,i,ans);//继续递推 
	return;
}
int main()
{
	int n,m;
	cin>>n>>m;
	xjj(n,m,0,ans);
	cout<<ans;
	return 0;
}
