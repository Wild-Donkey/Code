#include<bits/stdc++.h>
using namespace std;
int  a[10000001];
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1&&m==1) printf("%d",0);
    if((n==1&&m!=1)||(m==1&&n!=1)) printf("%d",1);
    int ans=(n-1)*(m-1);
    n--;m--;
    int l=min(n,m);
    for(int i=l;i>=2;i--)
    {
        a[i]=(n/i)*(m/i);
        for(int j=2*i;j<=l;j+=i)
        a[i]-=a[j];
        ans-=a[i];
    }
    cout<<(ans+2)%19268017;
}
