#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 19260817
using namespace std;
int f[30], n;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin >> n;
	f[0]=1;
	f[1]=1;
	f[2]=2;
	f[3]=5;
	f[4]=14;
	for(int i=4;i<=20;i++){
		if(i%2==0){
			for(int j=1;j<i/2;j++){
				f[i]+=f[i-j]*f[j-1]*2;
				f[i]%=MOD;
			}
			f[i]+=f[i/2]*f[i/2];
			f[i]%=MOD;
		}
		else{
			for(int j=1;j<=i/2;j++){
				f[i]+=f[i-j]*f[j-1]*2;
				f[i]%=MOD;
			}
		}
	}
	cout  << f[n] << endl;
	return 0;
}

