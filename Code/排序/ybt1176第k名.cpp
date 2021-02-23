#include<iostream>
#include<cstdio>
using namespace std;
double Point[105]= {0},Tmp[105]= {0};
int Number[105]= {0},Tp[105]= {0},n,k;
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
	/*	if(Point[i]==Point[j]) {
			if(Number[i])
		}*/
		if(Point[i]<Point[j]) {
			Tp[k]=Number[i];
			Tmp[k++]=Point[i++];
		} else {
			Tp[k]=Number[j];
			Tmp[k++]=Point[j++];
		}
	}
	while(i<=m) {
		Tp[k]=Number[i];
		Tmp[k++]=Point[i++];
	}
	while(j<=r) {
		Tp[k]=Number[j];
		Tmp[k++]=Point[j++];
	}
	for(int b=l; b<=r; b++) {
		Number[b]=Tp[b];
		Point[b]=Tmp[b];
	}
	return;
}
int main() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>Number[i]>>Point[i];
	}
	Merge(1,n);
	k=n-k+1;
	printf("%d %g\n",Number[k],Point[k]);
	return 0;
}
