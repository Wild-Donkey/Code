#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main(void)
{
	freopen("floder.in","r",stdin);
	freopen("floder.out","w",stdout);
	
	long long a,b,c,d,n,m;
	
	scanf("%lld%lld%lld",&a,&b,&c);
	
	d=c/b;
	c=c%b;
	
	if((__gcd(a,b)==min(a,b))&&c!=0)
	{
		printf("N0\n");
		printf("0\n");
		return 0;
	}
	
	for(long long i=1;;i++)
	{
	    if((b*i+c)%a==0)
	    {
	    	n=(b*i+c)/a;
	    	
	    	printf("YE5\n");
	    	printf("%lld\n",n+d);
	    	
	    	return 0;
		}
	}
} 
