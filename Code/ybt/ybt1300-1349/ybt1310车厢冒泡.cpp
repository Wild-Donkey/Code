#include<iostream>
using namespace std;
int A[100005];
void Change(int &x,int &y) {
	int t=x;
	x=y;
	y=t;
	return;
}
int Bubble(int x[]) {
	int Times=0;
	for(int i=x[0];i>1;i--) {
		for(int j=1;j<i;j++) {
			if(x[j]>x[j+1]) {//ÉýÐò
				Times++;
				Change(x[j],x[j+1]);
			//	cout<<x[j]<<"	"<<x[j+1]<<endl;
			}
		}
	}
	return Times;
}
int main() {
	cin>>A[0];
	for(int i=1;i<=A[0];i++) {
		cin>>A[i];
	}
	cout<<Bubble(A);
//	cout<<endl;
//	for(int i=1;i<=A[0];i++) {
//		cout<<A[i];
//	}
	return 0;
}
