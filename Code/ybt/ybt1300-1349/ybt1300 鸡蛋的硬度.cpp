#include<iostream>
#include<cstring>
using namespace std;
int n,m,f[1005][1005];
int main(){
	n=100;
	m=10;
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=n;i++){
		f[1][i]=i;
	}
	for(int i=1;i<=m;i++){
		f[i][0]=0;
	}
	for(int k=2;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){//��һ����j���� 
				f[k][i]=min(f[k][i],1+max(f[k-1][j-1]/*��һ����*/,f[k][i-j]/*��һ��û��*/));
			}
		}
	}
	while(cin>>n>>m){
		cout<<f[m][n]<<endl;		
	}
	return 0;
}
