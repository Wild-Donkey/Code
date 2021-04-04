#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int s[100005][2],sum[100005][2],color[100005],num[100005];
int n,m,ans;
int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	scanf ("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf ("%d",&num[i]);
    for(int i=1;i<=n;i++)
	{
        scanf ("%d",&color[i]);
        s[color[i]][i%2]++;
        sum[color[i]][i%2]=(sum[color[i]][i%2]+num[i])%10007;
    }
    for(int i=1;i<=n;i++)
	    ans=(ans+i*((s[color[i]][i%2]-2)*num[i]%10007+sum[color[i]][i%2]))%10007;
    
    printf ("%d\n",ans);
    return 0;
}
