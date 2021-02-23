#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[200005],b,c;
long long ans=0;
int main() {
	cin>>n>>c;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+0,a+n+1);
	for(int i=1;i<=n;i++) {
		b=a[i]+c;
		ans+=(upper_bound(a+0,a+n+1,b)-lower_bound(a+0,a+n+1,b));
	}
	cout<<ans<<endl;
	return 0; 
}
