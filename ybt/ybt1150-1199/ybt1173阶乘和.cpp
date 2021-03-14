#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[100005],Answer[100005],X,b,n;
void Times() {
	X=0;
	for(int i=1;i<=A[0];i++)//枚举因数的每一位 
	{
		A[i]=X+A[i]*b;
		X=A[i]/10;
		A[i]%=10;
	}
	A[++A[0]]+=X;
	while(A[A[0]]>=10) {
		A[++A[0]]+=A[A[0]-1]/10;
		A[A[0]-1]%=10;
	}
	while(A[A[0]]==0&&A[0]>1)
		A[0]--;
	return;
}
void Plus(int x[], int y[]) {
	x[0]=y[0]+1;
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]+=y[i];
		X=0;
		while(x[i]>=10) {
			x[i+1]++;
			x[i]-=10;
		}
	}
	while(x[x[0]]>10) {
		x[++x[0]]++;
		x[x[0]-1]-=10;
	}
	while(x[x[0]]==0&&x[0]>1)
		x[0]--;
	return;
}
int main() {
	cin>>n;
	if(n==0) {
		cout<<0<<endl;
		return 0;
	}
	A[0]=1;
	A[1]=1;
	Answer[1]=1;
	for(b=2;b<=n;b++) {
		Times();
		Plus(Answer,A);
	}
	for(int i=Answer[0];i>=1;i--)
	{
		cout<<Answer[i];
	}
	return 0;
}
