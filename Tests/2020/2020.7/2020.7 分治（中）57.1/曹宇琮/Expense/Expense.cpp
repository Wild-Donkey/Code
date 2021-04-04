#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long m,n;
long long a[200000];
bool _pd(long long x){
    long long tot = 0,tot_i = 1;
    for(long long i = 1;i <= n; i++){
        if(tot + a[i] <= x){
            tot += a[i];
        }else{
            tot = a[i];
            tot_i++;
        }
    }
    return tot_i > m;
}
int main(){
    freopen("Expense.in","r",stdin);
    freopen("Expense.out","w",stdout);
    cin >> n >> m;
    long long l = 0,r = 0,mid;
    for(long long i = 1;i <= n; i++){
        cin >> a[i];
        r += a[i];
    }
    while(l < r){
        mid = (l + r) >> 1;
        if(_pd(mid)){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}

/*
7 5
200 300 300 200 500 221 420
*/