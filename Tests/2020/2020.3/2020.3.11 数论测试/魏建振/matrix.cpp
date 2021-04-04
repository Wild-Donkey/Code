#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    long long n,m,s=0,l=19268017;
    cin>>n>>m;
    for(long long i=1;i<n;i++)
    for(long long j=1;j<m;j++)
    if(gcd(i,j)==1)
    s++;
    cout<<(s+2)%l;
    return 0;
}
