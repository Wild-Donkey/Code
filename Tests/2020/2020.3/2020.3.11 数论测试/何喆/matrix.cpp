#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=19268017;
typedef long long ll;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
ll phi(int q)
{
	ll ans=1;
	if (!(q&1)) return phi(q/2);
	for (int i=3;i<q;i++) if (!(gcd(i,q)-1)) ans=(ans+1)%MOD;
	return ans;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (!(gcd(n,m)-1)) cout<<phi(n)*phi(m)%MOD;
	else cout<<phi(n*m)%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
