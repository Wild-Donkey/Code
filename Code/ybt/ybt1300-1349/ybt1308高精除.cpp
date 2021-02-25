#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int A[10100],B[10100],C[10100],D[10100],E[10100],X;
bool Compare(int x[],int y[]) {//若x>=y返回0，y>x返回1。
	if(x[0]>y[0])
		return 0;
	if(x[0]<y[0])
		return 1;
	for(int i=x[0]; i>=1; i--) {
		if(x[i]>y[i])
			return 0;
		if(x[i]<y[i])
			return 1;
	}
	return 0;
}
void Read() {
	cin>>a>>b;
	A[0]=a.size();
	B[0]=b.size();
	for(int i=0; i<A[0]; i++) {
		A[A[0]-i]=a[i]-48;
	}
	for(int i=0; i<B[0]; i++) {
		B[B[0]-i]=b[i]-48;
	}
	C[0]=A[0]-B[0]+1;
	return;
}
void Minus(int x[], int y[]) {
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]=x[i]-y[i]-X;
		X=0;
		if(x[i]<0) {
			X++;
			x[i]+=10;
		}
	}
	while(x[x[0]]==0&&x[0]>1)
		x[0]--;
	return;
}
void Paste(int x[],int y[],int Pos) {
	for(int i=1; i<=x[0]; i++) {
		y[i+Pos-1]=x[i];
	}
	y[0]=Pos+x[0]-1;
	return;
}
void Divide() {
	for(int i=C[0]; i>0; i--) {
		memset(D,0,sizeof(D));
		Paste(B,D,i);
		while(!Compare(A,D)) {
			C[i]++;
			Minus(A,D);
		}
	}
	while(C[C[0]]==0&&C[0]>1)
		C[0]--;
	return;
}
int main() {
	Read();
	Divide();
//	Minus(A,B);
	for(int i=C[0]; i>=1; i--) {
		cout<<C[i];
	}
	cout<<endl;
	for(int i=A[0]; i>=1; i--) {
		cout<<A[i];
	}
	return 0;
}
