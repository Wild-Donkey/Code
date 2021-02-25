#include<iostream>
#include<cstring>
using namespace std;
int n,f[15][15][15][15]= {0},a[15][15]= {0}; //不能两次二维过的原因是：第一次保证路径最优并不能使最后的结果最优，所以需要同时考虑两次
void read(){
	int ra,rb,rc;
	cin>>ra>>rb>>rc;
	if((ra==0)&&(rb==0)&&(rc==0)){
		return;
	}
	else{
		a[ra][rb]=rc;
		read();
	}
}
int main() {
	cin>>n;
	read();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				for(int l=1; l<=n; l++) {
					f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]));
					f[i][j][k][l]+=a[i][j]+a[k][l];
					if((i==k)&&(j==l)) { //非法走法
						f[i][j][k][l]-=a[i][j];
					}
				}
			}
		}
	}
	cout<<f[n][n][n][n]<<endl;
	return 0;
}
