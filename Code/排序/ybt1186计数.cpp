#include<iostream>
using namespace std;
int x[100005],y[100005],Ans[10005],n;
int main() {
	cin>>x[0];
	if(x[0]%2)
		n=x[0]/2+1;
	else
		n=x[0]/2;
	for(int i=1; i<=x[0]; i++) {
		cin>>x[i];
	}
	for(int i=1; i<=x[0]; i++) {
		Ans[x[i]+100]++;
		if(Ans[x[i]+100]>=n) {
			cout<<x[i]<<endl;
			return 0;
		}
	}
	cout<<"no"<<endl;
	return 0;
}
