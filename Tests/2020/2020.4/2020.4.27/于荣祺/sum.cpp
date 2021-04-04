#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int num[10000],color[1000];
int n,m;
long long ans=0;

int main()
{   
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i)cin >> num[i];
    for(int i=1;i<=n;++i)cin >> color[i];
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(color[i] == num[2*j-i])ans+=(2*j*(num[i]+num[2*j-i]))%10007;
    cout << ans;
    return 0;
}
