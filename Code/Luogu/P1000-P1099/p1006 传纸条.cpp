#include<iostream>
#include<cstring>
using namespace std;
int n,m,f[55][55][55][55]= {0},a[55][55]= {0}; //不能两次二维过的原因是：第一次保证路径最优并不能使最后的结果最优，所以需要同时考虑两次
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=n; k++) {
				for(int l=1; l<=m; l++) {
					f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]));
					f[i][j][k][l]+=a[i][j]+a[k][l];
					if((i==k)&&(j==l)) { //非法走法
						if(((i!=n)||(j!=m))&&((i!=1)||(j!=1))) { //前后两步这样走合法
							f[i][j][k][l]=-0x3f3f3f3f;
						}
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<" "<<a[i][j]<<" "<<a[k][l]<<endl;
				}
			}
		}
	}
	cout<<f[n][m][n][m]<<endl;
	return 0;
}
