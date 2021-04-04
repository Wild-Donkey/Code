#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
	long long s,a,b;
    double x;
    scanf("%d%d%d",&s,&a,&b);
    x=(b+a)*s/(b+3*a);
    printf("%.2lf\n",x/b+(s-x)/a);
    return 0;
}
