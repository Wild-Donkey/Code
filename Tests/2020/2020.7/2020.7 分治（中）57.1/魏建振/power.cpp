#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
long long qsm(long long x, long long n)
{
    long long a=1;
    while(n)
    {
        if(n&1)
        a=a*x;
        n>>=1;
        x*=x;
    }
    return a;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n,x;
	scanf("%d%d",&x,&n);
	printf("%d\n",qsm(x,n));
	return 0;
}
