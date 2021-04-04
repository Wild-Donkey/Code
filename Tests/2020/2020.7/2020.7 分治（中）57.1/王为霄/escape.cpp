#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define itn int
#define ll long long
using namespace std;
double l,v1,v2;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%lf%lf%lf",&l,&v1,&v2 );
	double g = (l*(v1 + v2)) / (2 * v1 + v1 + v2);
    double ans = (l - g) / v1 + g / v2;
    printf("%.2lf",ans);
    return 0;
}
