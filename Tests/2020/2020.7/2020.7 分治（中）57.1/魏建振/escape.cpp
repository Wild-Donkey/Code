#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
using namespace std;
double l,a,b,ans,x;
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    scanf("%lf%lf%lf",&l,&a,&b);
    x=(l*(a+b))/(3*a+b);
    ans=(l-x)/a+x/b;
    printf("%.2lf\n",ans);
    return 0;
}  
