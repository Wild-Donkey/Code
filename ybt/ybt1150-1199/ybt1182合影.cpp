#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool Sex[1005],z[1005];
string sex;
double x[1005],y[1005];
bool bj=0;
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(x[i]<=x[j]) {
			z[k]=Sex[i];
			y[k++]=x[i++];
		} else {
			z[k]=Sex[j];
			y[k++]=x[j++];
		}
	}
	while(i<=m) {
		z[k]=Sex[i];
		y[k++]=x[i++];
	}
	while(j<=r) {
		z[k]=Sex[j];
		y[k++]=x[j++];
	}
	for(int b=l; b<=r; b++) {
		Sex[b]=z[b];
		x[b]=y[b];
	}
	return;
}
int main() {
	cin>>x[0];
	for(int i=1; i<=x[0]; i++) {
		cin>>sex;
		if(sex[0]=='f')//Å®true£¬ÄÐfalse
			Sex[i]=1;
		cin>>x[i];
	}
	Merge(1,x[0]);
	for(int i=1; i<=x[0]; i++) {
		if(!(Sex[i]))
			printf("%.2f ",x[i]);
	}
	for(int i=x[0]; i>=1; i--) {
		if(Sex[i])
			printf("%.2f ",x[i]);
	}
	cout<<endl;
	return 0;
}
