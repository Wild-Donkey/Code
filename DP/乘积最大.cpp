#include<iostream>
#include<string>
using namespace std;
string s;
int n,K;
long long ans=0,f[10][15]={0};
long long Get(int x,int y){//������˵�ͳ��� 
	long long gt=0;
	for(int Gi=0;Gi<y;Gi++){
		gt*=10;
		gt+=s[x+Gi-1]-'0';//s���Ǵ�0��n-1�洢�� 
	}
	return gt;
}
int main(){
	cin>>n>>K>>s;
	for(int i=1;i<=n;i++){
		f[1][i]=Get(1,i);
	}
	for(int i=2;i<=K;i++){//ö�ٳ˺� 
		for(int j=i;j<n;j++){//ö��λ
			for(int k=i-1;k<j;k++){//ö�ٶϵ� 
				f[i][j]=max(f[i][j],f[i-1][k]*Get(k+1,j-k));
			}
		} 
	}
	for(int i=K;i<n;i++){
		ans=max(ans,f[K][i]*Get(i+1,n-i));
	}
	cout<<ans<<endl;
	return 0;
}
