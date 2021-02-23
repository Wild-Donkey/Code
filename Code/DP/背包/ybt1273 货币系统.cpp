#include<iostream>
using namespace std;
long long n,t,f[100005],a[30000];
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=t;j++	){
			f[j]+=f[j-a[i]];
		}
	}
	cout<<f[t]<<endl;
	return 0;
}
