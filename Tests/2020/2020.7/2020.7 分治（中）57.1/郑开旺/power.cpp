#include<iostream>
#include<cstdio>
using namespace std;
long long ksm(int m,int n)
{
    long long ans=1;
    while(n>0)
    {
        if(n%2==1) ans*=m;
        m=m*m;
        n/=2;
    }
    return ans;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int x,y;
    cin>>x>>y;
    cout<<ksm(x,y);
    printf("\n");
    return 0;
}
