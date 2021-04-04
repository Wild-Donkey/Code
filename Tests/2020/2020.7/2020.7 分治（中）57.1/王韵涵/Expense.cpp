#include<bits/stdc++.h>
#define MAXNMAX 1e9

using namespace std;

int N,M;
int num[100090];

inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9')
   {
		if(ch=='-')w=-1;
		ch=getchar();
   }
   while(ch>='0'&&ch<='9')
		s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline bool check(int mm)
{
	int ans=0;
	long long sum=0;
	for(int i=1;i<=N;i++)
	{
		if(num[i]>mm)
		{
			return 0;
		}
		if(num[i]+sum>mm)
		{
			ans++;
			sum=0;
		}
		sum+=num[i];
	}
	ans++;
	return ans<=M;
}

int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	N=read();
	M=read();
	for(int i=1;i<=N;i++)
	{
		num[i]=read();
	}
	long long l=0;
	long long r=MAXNMAX;
	long long mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
