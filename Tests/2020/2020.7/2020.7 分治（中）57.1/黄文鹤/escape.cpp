#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstring>
using namespace std;

double a,b,s,x,t;

int main(void)
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	
	scanf("%lf%lf%lf",&s,&a,&b);
	x=(2*a*s)/(b+3*a);
	t=(s-x)/b+x/a;
	printf("%0.2lf",t); 
	return 0;
} 
// |___x___|____s-2x____|___x___|
