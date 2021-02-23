#include<iostream>
#include<cstring>
using namespace std;
string a,b,c;
int A[1005],B[1005],C[2005],x;
void Read(){
	cin>>a>>b;
	A[0]=a.size();
	B[0]=b.size();
	for(int i=0; i<A[0]; i++) {
		A[A[0]-i]=a[i]-48;
	}
	for(int i=0; i<B[0]; i++) {
		B[B[0]-i]=b[i]-48;
	}
	C[0]=A[0]+B[0];
	return;
}
void Solve() {
	x=0;
	for(int i=1;i<=A[0];i++)//枚举因数A的每一位 
	{
		x=0;
		for(int j=1;j<=B[0];j++){//枚举因数B的每一位 
			C[i+j-1]+=x+A[i]*B[j];
			x=C[i+j-1]/10;
			C[i+j-1]%=10;
		} 
		C[B[0]+i]+=x;
	}
	C[0]=A[0]+B[0];
	while(C[C[0]]==0&&C[0]>1)
		C[0]--;
	return;
}
int main() {
	Read();
	Solve();
	for(int i=C[0];i>=1;i--)
	{
		cout<<C[i];
	}
	return 0;
}
