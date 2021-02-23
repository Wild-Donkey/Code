#include<iostream>
using namespace std;
long long n,k,f[505];
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		f[i]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=2;j--) {
			f[j]=f[j-1]+j*f[j];
		}
	cout<<f[k]<<endl;
	return  0;
}
