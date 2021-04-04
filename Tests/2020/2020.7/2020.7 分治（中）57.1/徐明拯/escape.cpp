#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double x,y,v1,v2,s;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	cin>>s>>v1>>v2;
	y=s/((2*v1*v2)/(v1+v2)+v2);
	x=((2*v2)/(v1+v2))*y;
	double ans=x+y;
	printf("%.2lf\n",ans);
	return 0;
}

