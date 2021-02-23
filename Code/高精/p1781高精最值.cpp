#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[10100],B[10100],n,ans;
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
void Change(int x[],int y[]) {//x变成y 
	memset(x,0,sizeof(x));
	for(int i=0; i<=y[0]; i++) {
		x[i]=y[i];
	}
	return;
}
void Read() {
	memset(A,0,sizeof(A));
	cin>>a;
	A[0]=a.size();
	for(int i=0; i<A[0]; i++) {
		A[A[0]-i]=a[i]-48;
	}
	return;
}
int main() {
	cin>>n;
	B[0]=1;
	for(int j=1;j<=n;j++) {
		Read();
		if(!Compare(A,B))
		{
			Change(B,A);
			ans=j;
		}
	}
	cout<<ans<<endl;
	for(int i=B[0]; i>=1; i--) {
		cout<<B[i];
	}
	return 0;
}
