#include<iostream>
#include<cstdio>

using namespace std;
int n,m;
int a[100005];
inline int judging(int mid)
{
	int tot=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]>mid) {
			sum=a[i];
			tot++;
		}
		else {
			sum+=a[i];
		}
	}
	
	if(tot>m) return false;
	else return true;
}

int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	
	int maxn=0;
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	
	int lef=maxn,rig=0,mid;
	
	while(lef<rig)
	{
		mid=lef+rig>>1;
		if(judging(mid)) rig=mid;
		else lef=mid+1;
	}
	
	cout<<lef;
}
