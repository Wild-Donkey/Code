#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003,MOD=10007;
int s[N][2],sum[N][2],c[N],x[N];
int n,m,ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for (int i=1;i<=n;i++)
	{
        scanf ("%d",&c[i]);
        s[c[i]][i%2]++,sum[c[i]][i%2]=(sum[c[i]][i%2]+x[i])%MOD;
    }
    for (int i=1;i<=n;i++)
        ans=(ans+i*((s[c[i]][i%2]-2)*x[i]%MOD+sum[c[i]][i%2]))%MOD; 
    printf ("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
