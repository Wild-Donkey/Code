#include  <iostream>
#include  <cstdio>
#include  <algorithm>
#include  <cstring>
using namespace std;
typedef long long ll;
const int N= 19268017;
int n,a,b,d,mu[N],sum[N];
int tot,p[N];
bool vis[N];
void init()
{
    mu[1] = 1;
    for(int i = 2;i < N; i++)
    {
        if(!vis[i]) {mu[i] = -1;p[++tot] = i;}
        for(int j = 1;j  <= tot && i * p[j] < N; j++)
        {
            vis[i * p[j]] = true;
            if(i % p[j] == 0) break;
            mu[i * p[j]] = -mu[i];
        }
    }
    for(int i = 1;i < N;i++)
        sum[i]= sum[i-1] + mu[i];
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    init();
    cin >> a >> b;
    a--;b--;
    d =  1;
    a/= d;b/= d;
    static int mx;
    static ll ans;
    mx= min(a,b);ans= 0;
    for(int l= 1,r= 1;l <= mx;l= r+1)
    {
        r= min(a/(a/l),b/(b/l));
        ans+= (ll)(sum[r]-sum[l-1])*(a/l)*(b/l);
    }
    printf("%lld\n",ans+2);
}