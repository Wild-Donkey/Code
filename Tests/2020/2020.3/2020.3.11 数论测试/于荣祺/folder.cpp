#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <math.h>
using namespace std;
long long x,y;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b == 0){ x = 1;y = 0;return a;}
    long long r = exgcd(b,a%b,x,y);
    long long temp = y;
    y = x - (a/b) * y;
    x = temp;
    return r;
}
long long a,b,c;
int main(){
    freopen("folder.in","r",stdin);
    freopen("folder.out","w",stdout);
    cin >> a >> b >> c;

    if((!(a & 1)) && (!(b & 1)) && (c & 1)){//97.8%
        cout << "NO\n0\n";
        return 0;
    }
    long long tot = exgcd(a,b,x,y);

    while(x <= 0) x += b/tot;
    long long ans = (x*c/tot)%b % (b/tot);
 
    bool pd = 1;
    long long cc = (a % b) * ans % b % b;
    if(cc == c) pd = 1;
    else pd = 0;
    if(ans && (x * c % tot) == 0 && pd) cout << "YE5" << endl << ans << endl;
    else cout << "NO" << endl << 0 << endl;
    return 0;
}