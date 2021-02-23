#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long del,n,f[505][505]={0};
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[1][i];
	}
	for(int len=2;len<=n;len++){
		for(int l=1,r=l+len-1;r<=n;l++,r++){
			f[len][l]=abs(f[1][r]-f[1][l])*(r-l+1);
			for(int k=1;k<len;k++){
				f[len][l]=max(f[len][l],f[k][l]+f[len-k][l+k]);
			}
			//cout<<len<<" "<<l<<" "<<f[len][l]<<endl;
		}
	}
	cout<<f[n][1]<<endl;
	return 0;
}
