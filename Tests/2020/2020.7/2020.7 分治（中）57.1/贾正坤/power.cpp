#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 525525
#include <vector>
using namespace std;

long long x,n;
long long ans=1;
void mi(int x,int n){
	long long base=1ll*x;
	while(n){
		if(n%2){
			ans*=1ll*base;
		}
		base*=base;
		n>>=1;
	}
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> x >> n;
	mi(x,n);
	cout << ans << endl;
	return 0;
}

