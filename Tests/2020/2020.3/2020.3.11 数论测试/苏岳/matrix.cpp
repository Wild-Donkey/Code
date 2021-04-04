#include<stdio.h>
#define mo 19268017
int n,m;
long long f[10000001],ans;
int main()
{	
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout); 
    scanf("%d%d",&n,&m);
    if(n==1&&m==1){printf("0\n");return 0;}
    if(m==1||n==1){printf("1\n");return 0;}
	ans=(1ll*(n-1)*(m-1))%mo;
    n--;m--;
    int l=n;
    if(l>m)l=m;
    for(int i=n;i>=2;i--){
        f[i]=(1ll*(n/i)*(m/i))%mo ;
        for(int j =2*i;j<=l;j+=i)f[i]=(f[i]+mo-f[j])%mo;
        ans=(ans+mo-f[i])%mo;
    }
	ans=(ans+2)%mo;
    printf("%lld",ans);
    fclose(stdin);fclose(stdout);
	return 0;
}
