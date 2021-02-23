#include<iostream>
#include<cstring>
using namespace std;
int a[10005],n,k,tmp;
bool f[10005][105];
int main() {
	cin>>n>>k;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) {
		cin>>tmp;
		tmp%=k;//将每个数化为x*k+b的形式 
		a[i]=tmp;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<k;j++){
			f[i][j]=(f[i-1][(j-a[i]+k)%k]||f[i-1][(j+a[i]+k)%k]);
		}
	}
	if(f[n][0]){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
