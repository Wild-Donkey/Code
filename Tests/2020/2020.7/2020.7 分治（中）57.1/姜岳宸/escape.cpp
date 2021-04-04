#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int s,a,b;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
    cin>>s>>a>>b;
    double x=(double)2.0*s*a/(b+3.0*a);
    printf("%.2lf",(double)x/a+(s-x)/b);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
