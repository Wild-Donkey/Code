#include<iostream>
#include<cstdio>
using namespace std;
int Number[3005],Tp[3005],Point[3005],Tmp[3005],n,a[3005],d,c,e[3005];
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(Point[i]==Point[j]) {
			if(a[i]==a[j]) {
				if(Number[i]>Number[j]) {
					Tp[k]=Number[i];
					e[k]=a[i];
					Tmp[k++]=Point[i++];
				}
				 else {
					Tp[k]=Number[j];
					e[k]=a[j];
					Tmp[k++]=Point[j++];
				}
			} else {
				if(a[i]<a[j]) {
					e[k]=a[i];
					Tp[k]=Number[i];
					Tmp[k++]=Point[i++];
				}
				 else {
				 	e[k]=a[j];
					Tp[k]=Number[j];
					Tmp[k++]=Point[j++];
				}
			}
		} else {
			if(Point[i]<Point[j]) {
				e[k]=a[i];
				Tp[k]=Number[i];
				Tmp[k++]=Point[i++];
			} 
			else {
				Tp[k]=Number[j];
				e[k]=a[j];
				Tmp[k++]=Point[j++];
			}
		}
	}
	while(i<=m) {
		Tp[k]=Number[i];
		e[k]=a[i];
		Tmp[k++]=Point[i++];
	}
	while(j<=r) {
		e[k]=a[j]; 
		Tp[k]=Number[j];
		Tmp[k++]=Point[j++];
	}
	for(int b=l; b<=r; b++) {
		a[b]=e[b];
		Number[b]=Tp[b];
		Point[b]=Tmp[b];
	}
	return;
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>d>>c;
		Point[i]=a[i]+d+c;
		Number[i]=i;
	}
	Merge(1,n);
	for(int i=n; i>=max(n-4,1); i--) {
		cout<<Number[i]<<" "<<Point[i]<<endl;
	}
	return 0;
}
