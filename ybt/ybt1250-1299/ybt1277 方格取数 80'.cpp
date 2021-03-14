#include<iostream>
#include<cstring>
using namespace std;
int ans,n,f[15][15]={0},a[15][15]={0},lst[15][15][2]={0};
void read(){
	int ra,rb,rc;
	cin>>ra>>rb>>rc;
	if((ra==0)&&(rb==0)&&(rc==0)){
		return;
	}
	else{
		a[ra][rb]=rc;
		read();
	}
}
int main(){
	cin>>n;
	read();
	for(int i=1;i<=n;i++){//首次DP 
		for(int j=1;j<=n;j++){
			if(f[i-1][j]<f[i][j-1]){
				lst[i][j][0]=i;
				lst[i][j][1]=j-1;
				f[i][j]=f[i][j-1]+a[i][j];
			}
			else{
				lst[i][j][0]=i-1;
				lst[i][j][1]=j;
				f[i][j]=f[i-1][j]+a[i][j];
			}
		}
	}
	ans=f[n][n];
	int fx=n,fy=n,tx,ty;
	while((lst[fx][fy][0]!=0)||(lst[fx][fy][1]!=0)){//回溯 
		a[fx][fy]=0;
		tx=lst[fx][fy][0];
		ty=lst[fx][fy][1];
		fx=tx;
		fy=ty;
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){//再次DP 
		for(int j=1;j<=n;j++){
			if(f[i-1][j]<f[i][j-1]){
				f[i][j]=f[i][j-1]+a[i][j];
			}
			else{
				f[i][j]=f[i-1][j]+a[i][j];
			}
		}
	}
	ans+=f[n][n];
	cout<<ans<<endl; 
	return 0;
}
