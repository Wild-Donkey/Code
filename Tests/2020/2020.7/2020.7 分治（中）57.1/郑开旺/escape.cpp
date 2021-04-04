#include<iostream>
#include<cstdio>
using namespace std;
int s,a,b;
double x,ans,m,n;
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    cin>>s>>a>>b;
    m=1.0*(2*b-2*a)/(a*b+b*b)+(1.0*1/a)-(1.0*1/b);
    n=1.0*(b*s-a*s)/(a*b);
    x=1.0*n/m;
    ans=1.0*x/b+1.0*(s-x)/a;
    printf("%.2lf\n",ans);
    return 0;
}
