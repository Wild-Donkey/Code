#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100010];
long long l=0,r=0,mid=0;
int n,m;
bool js(long long s)
{
    long long p=0,w=0;
    for(int i=1;i<=n;++i)
    {
        if(p+a[i]<=s) p+=a[i];
        else
        {
            w++;
            p=a[i];
        }
    }
    if(w<m) return true;
    return false;
}
int main()
{
    freopen("Expense.in","r",stdin);
    freopen("Expense.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        l=l>a[i]? l:a[i];
        r+=a[i];
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(js(mid)==false) l=mid+1;
        else r=mid-1;
    }
    cout<<l;
    printf("\n");
    return 0;
}
/*
7 5
200 300 300 200 500 221 420
*/
