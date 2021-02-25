#include<iostream>
#include<cstring>
using namespace std;
string a;
int A[10100],b,X;
bool OK=0;
void Read() {
	cin>>a;
	A[0]=a.size();
	for(int i=0; i<A[0]; i++) {
		A[A[0]-i]=a[i]-48;
	}
	return;
}
void Divide() {
	X=0;
	for(int i=A[0]; i>=1; i--) {
		X=(A[i]+X*10)%b;
	}
	X%=b;
	return;
}
int main() {
	Read();
	for(b=2;b<=9;b++)
	{
		Divide();
		if(!X) {
			if(OK)
				cout<<" ";
			OK=1;
			cout<<b;
		}
	}
	if(OK)
	{
		cout<<endl;
		return 0;
	}
	cout<<"None"<<endl;
	return 0;
}
