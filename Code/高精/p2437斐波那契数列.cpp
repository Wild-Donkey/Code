#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int A[100005],B[100005],X=0,n,m;
void Plus(int x[], int y[]) {
	x[0]=max(x[0],y[0])+1;
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]=x[i]+y[i]+X;
		X=0;
		while(x[i]>=10) {
			X++;
			x[i]-=10;
		}
	}
	while(x[x[0]]==0&&x[0]>1)
		x[0]--;
	return;
} 
int main() {
	cin>>n>>m;
	n=m-n;
	A[0]=1;
	A[1]=1;
	B[0]=1;
	B[1]=1;
	for(int i=2;i<=n;i++) {
		if(i%2)
			Plus(B,A);
		else
			Plus(A,B);
	}
	if(n%2)
		for(int i=B[0]; i>=1; i--) {
			cout<<B[i];
		}
	else
		for(int i=A[0]; i>=1; i--) {
			cout<<A[i];
		}
	cout<<endl;
	return 0;
}
