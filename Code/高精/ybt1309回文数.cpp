#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[10100],B[10005],X,Binary,Step=0;

void Read(int x[]) {
	cin>>a;
	x[0]=a.size();
	for(int i=0; i<x[0]; i++) {
		if(a[i]>='A'&&a[i]<='Z')
			x[x[0]-i]=a[i]-55;
		else
			x[x[0]-i]=a[i]-48;
	}
	return;
}
void Turn(int x[], int y[]) {
	y[0]=x[0];
	int t;
	for(int i=1; i<=x[0]; i++)
	{
		y[x[0]-i+1]=x[i];
	}
	return;
}
void Plus(int x[], int y[]) {
	Turn(x,y);
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]=x[i]+y[i]+X;
		X=0;
		while(x[i]>=Binary) {
			X+=x[i]/Binary;
			x[i]-=Binary;
		}
	}
	if(X) {
		x[0]++;
		x[x[0]]+=X;
		X=0;
	}
	while(x[x[0]]==0&&x[0]>1)
		x[0]--;
	return;
}
bool Judge(int x[]) {
	if(x[x[0]]==0)
		return 0;
	int m=x[0]/2;
	for(int i=1;i<=m;i++)
	{
		if(x[i]!=x[x[0]-i+1])
			return 0;
	}
	return 1;
}
void Solve() {
	while(!Judge(A)) {
		if(Step>30)
		{
			Step=-1;
			return;
		}
		Plus(A,B);
		Step++;
	}
		return;
}
int main() {
	cin>>Binary;
	Read(A);
//	cout<<Judge(A)<<endl;
/*	for(int i=1;i<=30;i++)
	{
		Plus(A,B);
		for(int i=A[0]; i>=1; i--) {
			cout<<A[i];
		}
		cout<<endl;
	}*/
	Solve();
	if(Step==-1) {
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<Step<<endl;
	return 0;
}
