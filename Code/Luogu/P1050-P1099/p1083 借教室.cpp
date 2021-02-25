#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1000005],b[1000005],d,s,t;
long long ans=0;
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>d>>s>>t;
		b[s]+=d;
		b[s]-=d;
	}
	sort(a+0,a+n+1);
	for(int i=1;i<=n;i++) {
		b=a[i]+c;
		ans+=(upper_bound(a+0,a+n+1,b)-lower_bound(a+0,a+n+1,b));
	}
	cout<<ans<<endl;
	return 0; 
}
