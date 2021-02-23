#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool bj;
int Age1[105],Age2[105],n,c;
string a,Tmp1[105],Num1[105],Num2[105];
void Merge(int l, int r) {
	if(l==r)
		return;
	int m=(l+r)/2,i=l,j=m+1,k=l;
	Merge(l,m);
	Merge(m+1,r);
	while(i<=m&&j<=r) {
		if(Age1[i]>=Age1[j]) {
			Tmp1[k]=Num1[i];
			Age2[k++]=Age1[i++];
		} else {
			Tmp1[k]=Num1[j];
			Age2[k++]=Age1[j++];
		}
	}
	while(i<=m) {
		Tmp1[k]=Num1[i];
		Age2[k++]=Age1[i++];
	}
	while(j<=r) {
		Tmp1[k]=Num1[j];
		Age2[k++]=Age1[j++];
	}
	for(int b=l; b<=r; b++) {
		Num1[b]=Tmp1[b];
		Age1[b]=Age2[b];
	}
	return;
}
int main() {
	cin>>n;
	int p=0,q=0;
	for(int i=1; i<=n; i++) {
		cin>>a>>c;
		if(c>=60) {
			Num1[++p]=a;
			Age1[p]=c;
		} else
			Num2[++q]=a;
	}
	if(p)//老年人可以为0，最健康的人群就是老年人，人家可不需要挨号看病
		Merge(1,p);
	if(p)
		for(int i=1; i<=p; i++)
			cout<<Num1[i]<<endl;
	if(q)
		for(int i=1; i<=q; i++)
			cout<<Num2[i]<<endl;
	return 0;
}
