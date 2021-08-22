#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
ll n,k;
ll minn=2147483647;
ll t[1005],x[1005],y[1005];
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
bool ans;
int main(){
   freopen("A.in", "r", stdin);
   freopen("A.ans", "w", stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    cin>>t[i]>>x[i]>>y[i]; 
    for(ll i=1;i<=k;i++)
        for(ll j=1;j<=i;j++){
            ll c=lcm(t[i],t[j]);
            ll w=c*2; 
            while(c<=w){
					ll w1=(x[i]+(c/t[i]-1)*y[i])%n;
					ll w2=(x[j]+(c/t[j]-1)*y[j])%n;
					if(w1!=w2){
						ans=1;
						if(minn>c){
							minn=c;
							break;
						}
					}
					c+=c;
				}
        }
        if(ans)cout<<minn-1<<endl;
        else cout<<"Mystia will cook forever..."<<endl;
    return 0;
}
