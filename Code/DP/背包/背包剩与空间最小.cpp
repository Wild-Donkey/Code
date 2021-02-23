#include<iostream>
using namespace std;
int V,n,a[105],f[20005];
int main(){
	cin>>V>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=V;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=V;j++){
			if(j>=a[i]){
				f[j]=min(f[j],f[j-a[i]]);
			}
			//cout<<i<<" "<<j<<" "<<f[j]<<endl;
		}
	}
	cout<<f[V]<<endl;
	return 0;
}
