#include<iostream>
using namespace std;
int f[15][15],t,m,n;
int main() {
	f[0][0]=1;
	for(int i=1;i<=10;i++) {
		f[1][i]=1;
		f[i][1]=1;
		f[0][i]=1;
		f[i][0]=0;
	}
	for(int j=2; j<=10; j++) {//ö��������
		for(int i=2;i<=j;i++){//ƻ���������� 
			f[i][j]=f[i][i]; 
		}
		for(int i=j; i<=10; i++) {//ö��ƻ���� 
			f[i][j]=f[i][j-1]+f[i-j][j];
		//	cout<<i<<"	"<<j<<"	"<<f[i][j]<<endl; 
		}
	}
	cin>>t;
	for(int k=1;k<=t;k++) {
		cin>>m>>n;
		cout<<f[m][n]<<endl;
	}
	return 0;
}
