#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a,b;
long long ans;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>a>>b;
	ans=pow(a,b);
	cout<<ans<<endl;
	return 0;
}
