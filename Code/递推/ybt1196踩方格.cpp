#include<iostream>
using namespace std;
int f[25],n;
int main() {
	f[0]=0;
	f[1]=3;
	cin>>n;
	if(n==0) {
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++) {
		for(int j=i-2;j>=1;j--) {
			f[i]+=2*f[j];//2*(f[i-1]+...+f[1])
		}
		f[i]+=f[i-1]+4;//2*2+f[i-1]
	}
	cout<<f[n]<<endl;
	return 0;
}
