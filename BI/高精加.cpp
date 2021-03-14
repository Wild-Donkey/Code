#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int A[10100],B[10100],C[10100],X=0;
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
	C[0]=max(A[0],B[0])+1;
	return;
}
void Plus(int x[], int y[], int z[]) {
	for(int i=1; i<=z[0]; i++) { //枚举每一位
		z[i]=x[i]+y[i]+X;
		X=0;
		while(z[i]>=10) {
			X++;
			z[i]-=10;
		}
	}
	while(z[z[0]]==0&&z[0]>1)
		z[0]--;
	return;
}
int main() {
	Read();
	Plus(A,B,C);
	for(int i=C[0]; i>=1; i--) {
		cout<<C[i];
	}
	cout<<endl;
	return 0;
}
