#include<iostream>
#include<cstdio>
using namespace std;
int Number[5005],Tp[5005],Point[5005],Tmp[5005],n,m;
double T;
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(Point[i]==Point[j]) {
				if(Number[i]>Number[j]) {
					Tp[k]=Number[i];
					Tmp[k++]=Point[i++];
				}
				 else {
					Tp[k]=Number[j];
					Tmp[k++]=Point[j++];
				}
			}  else {
			if(Point[i]<Point[j]) {
				Tp[k]=Number[i];
				Tmp[k++]=Point[i++];
			} 
			else {
				Tp[k]=Number[j];
				Tmp[k++]=Point[j++];
			}
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
	cin>>n>>m;
	T=(m*1.500)/1;
	m=T;
	for(int i=1; i<=n; i++) {
		cin>>Number[i]>>Point[i];
	}
	Merge(1,n);
	int i=n;
	while(Point[i]>=Point[n-m+1]) {
		i--; 
	}
	i++;
	cout<<Point[i]<<" "<<n-i+1<<endl;
	for(int j=n;j>=i;j--)
		cout<<Number[j]<<" "<<Point[j]<<endl;
	return 0;
}
