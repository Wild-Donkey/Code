#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[100005],X,b,n;
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
int main() {
	cin>>n;
	if(n==0) {
		cout<<0<<endl;
		return 0;
	}
	A[0]=1;
	A[1]=1;
	for(b=2;b<=n;b++) {
		Times();
	}
	for(int i=A[0];i>=1;i--)
	{
		cout<<A[i];
	}
	return 0;
}
