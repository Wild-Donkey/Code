#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int f[50000];
int main()
{
    freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
    if(n==1&&m==1) 
    {
        printf("0\n");
        return 0;
    }
    ans=(n-1)*(m-1);
    n--;
	m--;
	int l=min(n,m);
   for(int i=l;i>=2;i--)
	{
		f[i]=(n/i)*(m/i);
		for(int j=2*i;j<=l;j+=i)
		f[i]-=f[j];
		ans-=f[i];
	}
    printf("%d",ans+2);
    return 0;
}
