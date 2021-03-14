#include<iostream>
using namespace std;
int a[100005],Tmp[100005];
long long ans=0;
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(a[i]<=a[j]) {
			Tmp[k++]=a[i++];
		}
		else {
			Tmp[k++]=a[j++];
			ans+=m-i+1;
		}
	}
	while(i<=m) {
		Tmp[k++]=a[i++];
	}
	while(j<=r) {
		Tmp[k++]=a[j++];
	}
	for(int b=l; b<=r; b++) {
		a[b]=Tmp[b];
	}
	return;
}
int main() {
	cin>>a[0];
	for(int i=1;i<=a[0];i++) {
		cin>>a[i];
	}
	Merge(1,a[0]);
	cout<<ans<<endl;
	return 0;
}
