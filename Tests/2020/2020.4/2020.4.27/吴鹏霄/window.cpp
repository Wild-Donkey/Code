#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,a[500000],len,l,r,p,Max[500000][30],Min[500000][30],ansMax[500000],ansMin[500000];
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a[i]);
        Max[i][0]=a[i];
        Min[i][0]=a[i];
    }
    len=(int)(log2(n));
    for(int j=1;j<=len;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
            Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n-m+1;i++){
        l=i;r=i+m-1;
        p=(int)(log2(r-l+1));
        ansMax[i]=max(Max[l][p],Max[r-(1<<p)+1][p]);
        ansMin[i]=min(Min[l][p],Min[r-(1<<p)+1][p]);
    }
    for(int i=1;i<=n-m+1;i++) cout<<ansMin[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n-m+1;i++) cout<<ansMax[i]<<" ";
    cout<<endl;
    return 0;
}
