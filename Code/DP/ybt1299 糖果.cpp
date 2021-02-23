#include<iostream>
#include<cstring>
using namespace std;
int n,k,f[1005][1005],a[1005];
int main(){
	memset(f,0,sizeof(f));
	cin>>n>>k;
	for(int i=1;i<k;i++){
		f[0][i]=-0x3fffffff;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<k;j++){
			f[i][j]=max(f[i-1][(j+k/*防负*/-(a[i]%k))%k]+a[i],f[i-1][j]);//选或不选
			//cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	cout<<f[n][0]<<endl;
	return 0;
}
