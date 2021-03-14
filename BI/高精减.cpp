#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int A[10100],B[10100],C[10100],x;
bool f=0;
bool pd(int x[],int y[]) {//若x>=y返回0，y>x返回1。 
	if(x[0]>y[0])
		return 0;
	if(x[0]<y[0])
		return 1;
	for(int i=x[0];i>=1;i--)
	{
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
	return;
}
void Solve() {
	if(pd(A,B))
	{
		cout<<"-";
	//	cout<<A[0]<<endl;
	//	cout<<B[0]<<endl;
		int t=0;
		t=A[0];
		A[0]=B[0];
		B[0]=t;
	//	cout<<A[0]<<endl;
	//	cout<<B[0]<<endl;
		for(int i=A[0];i>0;i--)
		{
			t=A[i];
			A[i]=B[i];
			B[i]=t;
		}
		/*for(int i=A[0];i>=0;i--)
			cout<<A[i];
		cout<<endl;
		for(int i=A[0];i>=0;i--)
			cout<<B[i];
		cout<<endl;*/
	}
	C[0]=A[0];
	for(int i=1; i<=A[0]; i++) { //枚举每一位
		C[i]=A[i]-B[i]-x;
		x=0;
		if(C[i]<0) {
			x++;
			C[i]+=10;
		}
	}
	int i=0;
/*	while(C[A[0]+i]<0)
	{
		C[A[0]+i+1]-=1;
		C[A[0]+i]+=10;
		i++;
	}*/
	while(C[C[0]]==0&&C[0]>1)
		C[0]--;
	return;
}
int main() {
	Read();
//	cout<<pd(A,B)<<endl;
	Solve();
	for(int i=C[0]; i>=1; i--) {
		cout<<C[i];
	}
	return 0;
}
