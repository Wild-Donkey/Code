#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,a[23];
bool pd(int un)
{
	int s=sqrt(un);
	for(int ii=2;ii<=s;ii++)
	{ 
		if(un%ii==0) return false; 
	} return true;
}
int faq(int sh,int sum,int start)
{
	int ans=0;
	if(sh==0)//û��ʣ�µ� 
		return pd(sum);
	for(int i=start;i<=n;i++)//����߽絽�ұ߽� 
	{
		ans+=faq(sh-1,sum+a[i],i+1);//ѡ��a[i]
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	n-=1;
	cout<<faq(k,0,0);
	return 0;
}
