#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	
	int s;
	int v1,v2;
	
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
	
	cin>>s>>v2>>v1;
	
	double x;
	
	x=(2*s*v2)/(3*v2+v1);
//	cout<<x;
	double t=x/v2+(s-x)/v1;
	
	printf("%.2lf",t);
}
