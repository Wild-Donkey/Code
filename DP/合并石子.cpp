#include<iostream>
#include<cstring>
using namespace std;
int n,a[105],f[105][105],sum[105]={0};
int main(){
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][1]=0;
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){//ö�����䳤�� 
		for(int j=1;j<=n-i+1;j++){//ö��������˵� 
			for(int k=1;k<i;k++){//ö������ϵ� 
				f[j][i]=min(f[j][i],f[j][k]+f[j+k][i-k]+sum[j+i-1]-sum[j-1]); 
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0; 
} 
