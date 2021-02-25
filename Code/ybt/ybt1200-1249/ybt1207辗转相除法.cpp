#include<iostream>
using namespace std;
int a,b;
int f(int a,int b) {
	if(b==0)
		return a;
	return f(b,a%b);
} 
int main() {
	cin>>a>>b;
	if(b>a) {
		int t=a;
		a=b;
		b=t;
	}
	cout<<f(a,b)<<endl;
	return 0;
}
