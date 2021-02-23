#include <bits/stdc++.h>

using namespace std;
int m[100005];
int N,M;

bool check(int x)
{
	int sum=0;
	int cnt=0;//把cnt模拟成分割线
	for(int i=1;i<=N;i++)
	{
		sum+=m[i];//一直往右贪心
		if(sum>x)//如果比mid大，那此时后面的数就不能加上了，前面数的和就是比mid小的数中最大的
		{
			cnt++;//画一条分割线
			sum=m[i];//sum要重新开始
		}
	}
	return cnt<=M-1;//这里就是当要分三段时，需要的分割线就是两条 
					//但是当cnt小于M-1时，说明此时的分法并不是最优解，还能按照这种分法继续往下分，所以返回true
					//如果cnt>M-1 那就跟题意不一样了，直接返回false
} 

int main()
{
	freopen("data.in","r",stdin);
	freopen("thestd.out","w",stdout);
	cin>>N>>M;
	int l=0;
	int r=0;
	for(int i=1;i<=N;i++)
	{
		cin>>m[i];
		l=max(l,m[i]);//根据题意确定最初的区间 如果不能确定，那可以把l初始化成1，把r初始化成一个比较大的数
		r+=m[i];
	}	
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
