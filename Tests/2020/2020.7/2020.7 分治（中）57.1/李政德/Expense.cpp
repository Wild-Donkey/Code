#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const double EPS = 1E6;
const int MOD = 1E9+7;
const int N = 1000000+5;
const int dx[8] = {-1,1,0,0,-1,-1,1,1};
const int dy[8] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
int n,m,a[N];
bool judge(int x) 
{
    int sum=0,group=1;
    for(int i=1; i<=n; i++) 
	{
        sum+=a[i];
        if(sum>x) 
		{
            sum=a[i];
            group++;
        }
    }
    if(group<=m)
        return true;
    else
        return false;
}
int main() 
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
    int left=0,right=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) 
	{
        scanf("%d",&a[i]);
        left=max(left,a[i]);
        right+=a[i];
    }
 
    while(left+1<right) 
	{
        int mid=(left+right)/2;
        if(judge(mid))
            right=mid;
        else
            left=mid;
    }
 
    if(judge(left))
        printf("%d\n",left);
    else
        printf("%d\n",right);
    return 0;
}

