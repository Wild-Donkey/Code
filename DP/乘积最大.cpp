#include<iostream>
#include<string>
using namespace std;
string s;
int n,K;
long long ans=0,f[10][15]={0};
long long Get(int x,int y){//区间左端点和长度 
	long long gt=0;
	for(int Gi=0;Gi<y;Gi++){
		gt*=10;
		gt+=s[x+Gi-1]-'0';//s串是从0到n-1存储的 
	}
	return gt;
}
int main(){
	cin>>n>>K>>s;
	for(int i=1;i<=n;i++){
		f[1][i]=Get(1,i);
	}
	for(int i=2;i<=K;i++){//枚举乘号 
		for(int j=i;j<n;j++){//枚举位
			for(int k=i-1;k<j;k++){//枚举断点 
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
