#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 19268017
using namespace std;
int n, m;
long long ans;
int pri[5000010], not_pri[10000010], top, phi[10000010];
void pre_phi(int n){
	not_pri[1]=1;
	phi[0]=phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!not_pri[i]){
			pri[++top]=i;
			phi[i]=i-1;
		}
		for(int j=1;i*pri[j]<=n;j++){
			not_pri[i*pri[j]]=1;
			if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
		}
//		cout << i  << " " << phi[i] << endl;
		phi[i]+=phi[i-1];
	}
}
int gcd(int a, int b){
	return (b==0)? a: gcd(b, a%b);
}
long long doit1(){
	long long ans;
	n--;
	pre_phi(n);
	ans=phi[n]%MOD*2;
	ans+=1;
	ans %= MOD;
	return ans;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w", stdout);
	cin >> n >> m;
	if(n==0 || m==0){
		cout << 0 << endl;
		return 0;
	}
	if(n==m){
		ans = doit1();
		cout << ans << endl;
		return 0;
	}
	if(n > m)	swap(n,m);
	n--,m--;
	pre_phi(n);
	for(int i=n+1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(gcd(i,j)==1)	ans++;
		}
		ans %= MOD;
	}//cout << ans << endl;
	ans+=phi[n]*2%MOD+1;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
    
