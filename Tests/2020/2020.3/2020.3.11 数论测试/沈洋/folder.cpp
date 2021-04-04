#include<cstdio>
#define C 19268017
using namespace std; 
int n,m;
long long f[10000001],ans;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1&&m==1)
	{printf("0\n");return 0;}
    if(m==1||n==1){
	printf("1\n");
	return 0;}
	ans=(1ll*(n-1)*(m-1))%C;
    n--;m--;
    int l=n;
    if(l>m)l=m;
    for(int i=n;i>=2;i--){
        f[i]=(1ll*(n/i)*(m/i))%C ;
        for(int j =2*i;j<=l;j+=i)f[i]=(f[i]+C-f[j])%C;
        ans=(ans+C-f[i])%C;
    }
    printf("%lld",(ans+2)%C);
    return 0;
}
