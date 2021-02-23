#include<iostream>
using namespace std;
int l,r,n,m,fx[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}},q[10005][2],cnt=0,ans[10005][2],fa[1005][1005];
bool a[1005][1005],flg=0;
void BFS(){
	int bx,by;
	while(l<r){
		int nx,ny;
		bx=q[l][0];
		by=q[l][1];
		a[bx][by]=1;
		l++;
		if((bx==n)&&(by==m)){
			flg=1;
			return;
		}
		for(int i=0;i<8;i++){
			nx=bx+fx[i][0];
			ny=by+fx[i][1];
			if((nx>0)&&(nx<=n)&&(ny>0)&&(ny<=m)){
				if(!a[nx][ny]){
					a[nx][ny]=1;
					q[r][0]=nx;
					q[r++][1]=ny;
					fa[nx][ny]=i;
				}
			}
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	l=1;
	r=2;
	q[l][0]=1;
	q[l][1]=1;
	BFS();
	if(flg==0){
		cout<<-1<<endl;
		return 0;
	}
	int nx,ny,tx,ty;
	nx=n;
	ny=m;
	while((nx>0)&&(nx<=n)&&(ny>0)&&(ny<=m)){
		ans[++cnt][0]=nx;
		ans[cnt][1]=ny;
		tx=nx;
		ty=ny;
		nx-=fx[fa[tx][ty]][0];
		ny-=fx[fa[tx][ty]][1];
	} 
	for(int i=cnt;i>=1;i--){
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}
