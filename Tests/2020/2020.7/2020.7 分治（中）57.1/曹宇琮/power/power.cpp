#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long x,n;
long long q_pow(long long a,long long b){
    long long tot = 1;
    while(b){
        if(b & 1) tot *= a;
        a *= a;
        b >>= 1;
    }
    return tot;
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin >> x >> n;
    cout << q_pow(x,n) << endl;
    return 0;
}