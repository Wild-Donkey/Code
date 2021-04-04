#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;

long long n,m,sum=1;

long long ksm(long long a,long long b)
{	
	if(a==0) return 0;
	if(a!=0&&b==0) return 1;
	
	ksm(a,b>>1);
	
	sum=sum*sum;
	
	if(b%2!=0) sum=sum*a;
	
	return sum;
}

int main(void)
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	
	printf("%lld\n",ksm(n,m));
	
	return 0;
}
