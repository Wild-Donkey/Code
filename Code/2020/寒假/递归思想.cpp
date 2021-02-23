#include<iostream>
using namespace std;//2939638431
int n;
void LHS(int a) {
	cout<<"从前有第"<<a<<"座山，山里有第"<<a<<"座庙，庙里有第"<<a<<"个老和尚给第"<<a<<"个小和尚讲第"<<a<<"个故事:	";
	if(a>=n){
		cout<<"故事结束了,共有"<<n<<"座山"; 
		return;
	}
	return LHS(a+1);
}
int main() {
	cin>>n;
	LHS(1);
	return 0;
}
