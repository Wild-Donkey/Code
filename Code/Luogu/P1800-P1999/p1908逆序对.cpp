#include<iostream>
#include<cstdio>
using namespace std;
int a[500005],Tmp[500005];
long long ans=0;
inline int Read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(a[i]<=a[j]) {
			Tmp[k++]=a[i++];
		} else {
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
	a[0]=Read();
	for(int i=1; i<=a[0]; i++) {
		a[i]=Read();
	}
	Merge(1,a[0]);
	cout<<ans<<endl;
	return 0;
}
