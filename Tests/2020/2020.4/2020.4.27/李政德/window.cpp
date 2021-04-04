#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int logn=25;
int n,m,le,ri,f[1000001][logn+1],f2[1000001][logn+1],mx[1000001],mn[1000001];
int main()
{
	freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&f[i][0]),f2[i][0]=f[i][0];
    for(int j=1;j<=logn;j++)
	{
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
    }
    for(int i=1;i<=n-m+1;i++){
        le=i,ri=i+m-1;
        int len=log2(ri-le+1);
        mx[i]=max(f[le][len],f[ri-(1<<len)+1][len]),mn[i]=min(f2[le][len],f2[ri-(1<<len)+1][len]);
    }
    for(int i=1;i<=n-m+1;i++){
        cout<<mn[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n-m+1;i++){
        cout<<mx[i]<<" "; 
    }
    return 0;
}
