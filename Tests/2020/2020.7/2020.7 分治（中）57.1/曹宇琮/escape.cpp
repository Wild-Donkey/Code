#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
double x,va,vb;
double l = 0,r,mid;
bool if_ok(double t){
    double t1 = (3 * vb * t - x)/(4 * vb);
    // cout << mid << ' ' << (2 * va * t1 + (vb * t - x) / 2) << endl;
    return (2 * va * t1 + (vb * t - x) / 2)> x;
}
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    cin >> x >> va >> vb;
    r = 100000000000;
    while(r - l > 0.0001){
        mid = (r + l) /2;
        if(if_ok(mid)){
            r = mid;
        }else l = mid;
        mid = (r + l) /2;
    }
    printf("%.2f\n",mid);
    return 0;
}
