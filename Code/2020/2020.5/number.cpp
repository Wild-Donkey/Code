#include<iostream>
#include<algorithm>
using namespace std;
int n, a[10005],b=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+0,a+n+1);
	for(int i=1; i<=n/2; i++) {
		b=max(b,a[i]+a[n-i+1]);
	}
	cout<<b;
	return 0;
}
