#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int A[100005],B[100005],P[100005],M[100005],T[100005],D[100005],Tmp[100005],X;
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
	M[0]=max(A[0],B[0]);
	D[0]=A[0]-B[0]+1;
	return;
}
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
void Paste(int x[],int y[],int Pos) {
	for(int i=1; i<=x[0]; i++) {
		y[i+Pos-1]=x[i];
	}
	y[0]=Pos+x[0]-1;
	return;
}

void Plus(int x[], int y[], int z[]) {
	z[0]=max(x[0],y[0])+1;
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
void Minus(int x[], int y[], int z[]) {
	X=0;
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		z[i]=x[i]-y[i]-X;
		X=0;
		while(z[i]<0) {
			X++;
			z[i]+=10;
		}
	}
	while(z[z[0]]==0&&z[0]>1)
		z[0]--;
	return;
}
void Times(int x[], int y[], int z[]) {
	for(int i=1;i<=x[0];i++)//枚举因数A的每一位 
	{
		X=0;
		for(int j=1;j<=y[0];j++){//枚举因数B的每一位 
			z[i+j-1]+=X+x[i]*y[j];
			X=z[i+j-1]/10;
			z[i+j-1]%=10;
		} 
		z[y[0]+i]+=X;
	}
	z[0]=x[0]+y[0];
	while(z[z[0]]==0&&z[0]>1)
		z[0]--;
	return;
}
void Divide(int x[], int y[], int z[]) {
	z[0]=max(x[0]-y[0]+1,1);
	for(int i=z[0]; i>0; i--) {
		memset(Tmp,0,sizeof(Tmp));
		Paste(y,Tmp,i);
		while(Compare(Tmp,x)) {
			z[i]++;
			Minus(x,Tmp,x);
		}
	}
	while(z[z[0]]==0&&z[0]>1)
		z[0]--;
	return;
}
int main() {
	Read();
	Plus(A,B,P);
	for(int i=P[0]; i>=1; i--) {
		cout<<P[i];
	}
	cout<<endl;
	if(Compare(A,B)) {//负数
		cout<<"-";
		Minus(B,A,M);
		for(int i=M[0]; i>=1; i--) {
			cout<<M[i];
		}
	}
	else {
		Minus(A,B,M);
		for(int i=M[0]; i>=1; i--) {
			cout<<M[i];
		}
	}
	cout<<endl;
	Times(A,B,T);
	for(int i=T[0]; i>=1; i--) {
		cout<<T[i];
	}
	cout<<endl;
	Divide(A,B,D);
	for(int i=D[0]; i>=1; i--) {
		cout<<D[i];
	}
	cout<<endl;
	for(int i=A[0]; i>=1; i--) {
		cout<<A[i];
	}
	cout<<endl;
	return 0;
}
