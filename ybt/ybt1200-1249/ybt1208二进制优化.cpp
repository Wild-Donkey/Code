#include<iostream>
using namespace std;
int a,mi[20];
void f(int x) {
	if(x==0) {
		cout<<0;
		return;
	}
	if(x==1) {
		cout<<"2(0)";
		return;
	}
	if(x==2) {
		cout<<"2";
		return;
	}
	int i=15;
	bool bj=0;
	while(x!=0) {//x依次减去2的i次方 
		if(x>=mi[i]) {
			x-=mi[i];
			if(bj)
				cout<<"+";
			if(i==1) {
				f(2);
				bj=1;
			}
			else {
				cout<<"2(";
				f(i);
				bj=1;
				cout<<")";
			}
		}
		i--;
	}
} 
int main() {
	cin>>a;
	mi[0]=1;
	for(int i=1;i<=15;i++) {
		mi[i]=mi[i-1]*2;
	}
	f(a);
	return 0;
}
