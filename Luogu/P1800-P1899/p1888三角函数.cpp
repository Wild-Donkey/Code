#include<iostream>
using namespace std;
int a,b,c,t,ans;
int main() {
	cin>>a>>b>>c;
	if(a>b) {
		t=a;
		a=b;
		b=t;
	}
	if(b>c) {
		t=b;
		b=c;
		c=t;
	}
	if(a>b) {
		t=a;
		a=b;
		b=t;
	}
	for(int i=2;i<=400000;i++) {
		if(!(a%i)&&!(c%i)) {
			a/=i;
			c/=i;
		}
	}
	cout<<a<<"/"<<c;
}
