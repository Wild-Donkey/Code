#include<iostream>
#include<cstring>
using namespace std;
long long f[505][505],a[505],s[505][505],m,n,Ans=0;//�ڴ���룬m���壬n��ѧУ 
int main() {
	cin>>m>>n;
	a[1]=0;
	for(int i=2;i<=m;i++) {
		cin>>a[i];
		a[i]+=a[i-1];
		//cout<<i<<"	"<<a[i]<<endl;
	}
	for(int i=1;i<=m;i++) {
		for(int l=1;l<=m-i;l++) {
			s[l][l+i]=s[l][l+i-1]+a[l+i]-a[l+(i/2)];
			//cout<<l<<" "<<i<<" "<<s[l][l+i]<<endl;
		}
	}
	memset(f,0x7f,sizeof(f));
	for(int i=1;i<=m;i++){
		f[i][1]=s[1][i];
	}
	for(int j=2;j<=n;j++) {//ö��ѧУ�� 
		for(int i=j;i<=m;i++) {//ö�ٴ�����������С��ѧУ���� 
			for(int k=1;k<i;k++) {//ö�ٵ�j��ѧУ�ķ������䣨ǰ���ᵽ�����ұգ���߽磨���ô��ڻ�����ܴ�����i�� 
				f[i][j]=min(f[i][j],f[k][j-1]+s[k+1][i]);
				//cout<<i<<" "<<j<<"	"<<f[i][j]<<endl;
			} 
		}
	}
	cout<<f[m][n]<<endl;
	return 0;
}
