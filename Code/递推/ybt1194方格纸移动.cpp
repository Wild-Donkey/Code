#include<iostream>
using namespace std;
int a[105][105],m,n;
int main() {
	cin>>m>>n;
	a[1][1]=1;
	for(int i=1; i<=n; i++) {
		a[1][i]=1;
	}
	for(int i=1; i<=m; i++) {
		a[i][1]=1;
	}
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=m; j++) {
			a[j][i]=a[j-1][i]+a[j][i-1];
		}
	}
	cout<<a[m][n]<<endl;
	return 0;
}
