#include<iostream>
using namespace std;
int mi[20],x,k;
char ch;
bool a[100005];
bool f(int y) {
	if(y==k)
		return true;
	if((y-1)%3);
	else {
		if(f((y-1)/3))
			return true;
	}
	if((y-1)%2);
	else {
		if(f((y-1)/2))
			return true; 
	}
	return false;
}
int main() {
	cin>>k>>ch>>x;
	if(f(x))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
