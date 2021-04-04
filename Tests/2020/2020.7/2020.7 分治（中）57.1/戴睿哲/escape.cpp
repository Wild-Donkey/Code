#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	int s,a,b;
	float x;
	cin>>s>>a>>b;
	x=2.0*s*a/(b+3.0*a);
	x=x/a+(s-x)/b;
    printf("%.2f",x);
    return 0;
}


//  两位小数 
