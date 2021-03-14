#include<iostream>
#include<cstring>
using namespace std;
int ans,n,m,f[105][105]={0},a[105][105];
int DP(int x,int y){
	if(f[x][y]){
		return f[x][y];
	}
	if(a[x-1][y]<a[x][y]){
		f[x][y]=max(f[x][y],DP(x-1,y)+1);
	}
	if(a[x+1][y]<a[x][y]){
		f[x][y]=max(f[x][y],DP(x+1,y)+1);
	}
	if(a[x][y-1]<a[x][y]){
		f[x][y]=max(f[x][y],DP(x,y-1)+1);
	}
	if(a[x][y+1]<a[x][y]){
		f[x][y]=max(f[x][y],DP(x,y+1)+1);
	}
	return f[x][y];
}
int main(){
	cin>>m>>n;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,DP(i,j));
		}
	}
	ans++;
	cout<<ans<<endl; 
	return 0;
}
