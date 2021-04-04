#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[1000000],b[1000000],d[1000000],x[1000000];
long long cmp(long long y,long long z)
{
    return y>z;
}
int main()
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
	long long k,n;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    cin>>a[i];
    for(long long i=1;i<=n;i++)
    b[i]=a[i];
    for(long long i=1;i<=n-k+1;i++)
    {
    sort(b+i,b+i+k,cmp);
    d[i]=b[i];
    x[i]=b[i+k-1];
    for(int j=i;j<=i+k-1;j++)
    b[j]=a[j];
    }
    for(int i=1;i<=n-k+1;i++)
    cout<<x[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n-k+1;i++)
    cout<<d[i]<<" ";
    cout<<endl;
    return 0;
}
