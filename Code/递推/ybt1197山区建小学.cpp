#include<iostream>
#include<cstring>
using namespace std;
long long f[505][505],a[505],s[505][505],m,n,Ans=0;//邻村距离，m个村，n个学校 
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
	for(int j=2;j<=n;j++) {//枚举学校数 
		for(int i=j;i<=m;i++) {//枚举村子数（不得小于学校数） 
			for(int k=1;k<i;k++) {//枚举第j所学校的服务区间（前文提到，左开右闭）左边界（不得大于或等于总村子数i） 
				f[i][j]=min(f[i][j],f[k][j-1]+s[k+1][i]);
				//cout<<i<<" "<<j<<"	"<<f[i][j]<<endl;
			} 
		}
	}
	cout<<f[m][n]<<endl;
	return 0;
}
