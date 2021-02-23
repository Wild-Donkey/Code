#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool bj;
int n;
string a,Tmp1[100005],Num1[100005];
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(Num1[i]<=Num1[j])
			Tmp1[k++]=Num1[i++];
		else
			Tmp1[k++]=Num1[j++];
	}
	while(i<=m)
		Tmp1[k++]=Num1[i++];
	while(j<=r)
		Tmp1[k++]=Num1[j++];
	for(int b=l; b<=r; b++)
		Num1[b]=Tmp1[b];
	return;
}
int main() {
	n=1;
	int j=1;
	while(cin>>Num1[n++]);
	n--;
	Merge(1,n);
	for(int i=1; i<=n; i++)
		if(Num1[i]!=Num1[i-1])
			cout<<Num1[i]<<endl;
	return 0;
}
