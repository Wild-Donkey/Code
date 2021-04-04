#include<iostream>
#include<cstdio>
using namespace std;
int f[21];
int main()
{
	f[1]=1;f[2]=2;f[3]=5;
	freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    f[i]=f[i-1]*(4*i-2)/(i+1);
    cout<<f[n];
}
