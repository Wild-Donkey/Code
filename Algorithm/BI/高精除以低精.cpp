#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[10100],C[10100]= {0},b,X;
void Read() {
	cin>>a;
	A[0]=a.size();
	for(int i=0; i<A[0]; i++) {
		A[A[0]-i]=a[i]-48;
	}
	C[0]=A[0];
	return;
}
void Divide() {
	X=0;
	for(int i=A[0]; i>=1; i--) {
		C[i]=(A[i]+X*10)/b;
		X=(A[i]+X*10)%b;
		if(C[i]>10)
		{
			C[i+1]+=C[i]/10;
			C[i]%=10;
		}
	}
	while(C[C[0]]==0&&C[0]>1)
		C[0]--;
	return;
}
int main() {
	Read();
	cin>>b;
	Divide();
	for(int i=C[0]; i>=1; i--) {
		cout<<C[i];
	}
	cout<<endl<<X<<endl;
	return 0;
}
