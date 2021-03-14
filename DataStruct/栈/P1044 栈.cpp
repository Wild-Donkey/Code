#include<iostream>
using namespace std;
int n,f[25]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
int main(){
	cin>>n;
	/*f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]+=f[j-1]*f[i-j];
		}
		cout<<i<<" "<<f[i]<<endl;
	}*/
	cout<<f[n]<<endl;
	return 0; 
}
