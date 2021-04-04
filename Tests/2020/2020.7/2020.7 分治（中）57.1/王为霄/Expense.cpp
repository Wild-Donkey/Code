#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define itn int
#define ll long long
using namespace std;
int n,m,a[1000000];
void init()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
} 
int judge(int x)
{
    int money=0,month=0,d,i;
    for(i=1;i<=n;i++)
    {
        money+=a[i];
        if(money>=x)
        {
            month++;
            if(a[i]<x)
                money=a[i];
            else
                return 1;
        }
    }
    return month>=m;
}
int main()
{
	init();
    int left,right,mid;
    int tot=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tot+=a[i];
    }
    left=1;
    right=tot;
    while(left+1<right)
    {
        mid=(left+right)/2;
        if(judge(mid))
            left=mid;
        else
            right=mid;
    }
    if(judge(left))
        cout<<left<<endl;
    else
        cout<<right<<endl;
    return 0;
} 
