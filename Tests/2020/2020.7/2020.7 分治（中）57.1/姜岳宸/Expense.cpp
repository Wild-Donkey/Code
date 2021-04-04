#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define re register
using namespace std;
int a[100001];
int n,m;
int check(int num)
{
	int r=0,temp=0;
	for(int i=1;i<=n;i++)
	{
		if(temp+a[i]<=num)
		{
			temp+=a[i];
		}
		else
		{
			temp=a[i];
			r++;
		}
	}
	return r<m;
}
int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	cin>>n>>m;
	int left=0,right=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		right+=a[i];
		left=max(left,a[i]);
	} 
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(check(mid)) right=mid-1;
		else left=mid+1;
	}
	cout<<left<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

