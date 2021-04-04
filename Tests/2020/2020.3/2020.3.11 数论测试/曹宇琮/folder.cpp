#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
long long x,y;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
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
    // if(a * b * c <= 1000000){
    //     long long tot = 0;
    //     long long cnt,Find_ans = 1;
    //     while(tot % b != c){
    //         tot += a;
    //         cnt++;
    //         if(cnt > a * b){
    //             Find_ans = 0;
    //             break;
    //         }
    //     }
    //     if(Find_ans && tot / a){ 
    //         cout << "YE5" << endl;
    //         cout << tot/a << endl;
    //     }
    //     else cout << "NO\n0\n";
    //     return 0;
    // }   
    if((!(a & 1)) && (!(b & 1)) && (c & 1)){//97.8%
        cout << "NO\n0\n";
        return 0;
    }
    long long tot = exgcd(a,b,x,y);
    // cout << tot << endl;
    // cout << x << ' ' << y << endl;
    while(x <= 0) x += b/tot;
    long long ans = (x*c/tot)%b % (b/tot);
    // cout << x << ' ' << y << endl;
    // cout << x % tot << endl;
    bool pd = 1;
    long long cc = (a % b) * ans % b % b;
    if(cc == c) pd = 1;
    else pd = 0;
    if(ans && (x * c % tot) == 0 && pd) cout << "YE5" << endl << ans << endl;
    else cout << "NO" << endl << 0 << endl;
    return 0;
}