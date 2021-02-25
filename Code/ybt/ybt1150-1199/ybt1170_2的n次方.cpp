#include<iostream>
#include<cstring>
using namespace std;
int A[1000005],X,n;
void Plus(int x[]) {
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]=x[i]+x[i]+X;
		X=0;
		while(x[i]>=10) {
			X+=x[i]/10;
			x[i]-=10;
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
int main() {
	cin>>n;
	A[0]=1;
	A[1]=1;
	for(int i=1;i<=n;i++) {
		Plus(A);
	}
	for(int i=A[0]; i>=1; i--) {
		cout<<A[i];
	}
	return 0;
}
