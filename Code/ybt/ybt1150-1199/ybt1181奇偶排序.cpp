#include<iostream>
using namespace std;
int x[100005],y[100005];
bool bj=0;
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(x[i]<=x[j]) {
			y[k++]=x[i++];
		} else {
			y[k++]=x[j++];
		}
	}
	while(i<=m) {
		y[k++]=x[i++];
	}
	while(j<=r) {
		y[k++]=x[j++];
	}
	for(int b=l; b<=r; b++) {
		x[b]=y[b];
	}
	return;
}
int main() {
	x[0]=10;
	for(int i=1; i<=x[0]; i++) {
		cin>>x[i];
	}
	Merge(1,x[0]);
	for(int i=x[0]; i>=1; i--) {
		if(bj&&x[i]%2)
			cout<<" ";
		if(x[i]%2) {
			bj=1;
			cout<<x[i];
		}
	}
	for(int i=1; i<=x[0]; i++) {
		if(bj&&!(x[i]%2))
			cout<<" ";
		if(!(x[i]%2)) {
			bj=1;
			cout<<x[i];
		}
	}
	cout<<endl;
	return 0;
}
