#include<iostream>
#include<cstdio>
using namespace std;
long long a[100005],b[2][100005];
long long c[3][100005],d[3][100005];
long long n,m,s,i,t;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
    for(i=1;i<=n;i++)
    {
        cin>>t;
        if(i%2==1)
        {
            s=(s+c[0][t]%10007+i*c[1][t]%10007+a[i]*c[2][t]%10007+b[0][t]*i*a[i]%10007)%10007;
            c[0][t]=(c[0][t]+a[i]*i)%10007;
            c[1][t]=(c[1][t]+a[i])%10007;
            c[2][t]=(c[2][t]+i)%10007;
            b[0][t]++;
        }
        else
        {
            s=(s+d[0][t]%10007+i*d[1][t]%10007+a[i]*d[2][t]%10007+b[1][t]*i*a[i]%10007)%10007;
            d[0][t]=(d[0][t]+a[i]*i)%10007;
            d[1][t]=(d[1][t]+a[i])%10007;
            d[2][t]=(d[2][t]+i)%10007;
            b[1][t]++;
        }
    }
    cout<<s%10007;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
