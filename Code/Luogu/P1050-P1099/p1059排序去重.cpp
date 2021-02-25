#include<iostream>
using namespace std;
int x[100005],y[100005];
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
	cin>>x[0];
	for(int i=1; i<=x[0]; i++) {
		cin>>x[i];
	}
	Merge(1,x[0]);
	int i=1,j=1;
	while(i<=x[0]) {
		if(x[i]!=x[i+1])
			y[j++]=x[i];
		i++;
	}
	cout<<--j<<endl;
	for(int i=1; i<=j; i++) {
		cout<<y[i]<<" ";
	}
	return 0;
}
