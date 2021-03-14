#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,st[1005][1005]={0},fx[5][2]={{0,0},{1,-2},{2,-1},{2,1},{1,2}},now[2],cnt=0,ans[1005];
bool flg=0, no[1005][1005]={0};
void DFS(int x,int y){
	if(flg){
		return;
	}
	if((x==n)&&(y==m)){
		flg=1;
		return;
	}
	if(n-x<(m-y)>>1){
		no[x][y]=1;
		return;
	}
	if(no[x][y]){
		return;
	}
	int nx,ny;
	for(int i=1;i<=4;i++){
		nx=x+fx[i][0];
		ny=y+fx[i][1];
		if((nx<=n)&&(ny>0)&&(ny<=m)){
			st[nx][ny]=i;
			DFS(nx,ny);
			no[nx][ny]=1;
		}
	}
	return;
}
int main(){
	//freopen("knight.in","r",stdin);
	//freopen("knight.out","w",stdout);
	cin>>n>>m;
	DFS(1,1);
	if(st[n][m]==0){
		cout<<-1<<endl;
		return 0;
	}
	now[0]=n;
	now[1]=m;
	while(st[now[0]][now[1]]){
		int t[2];
		ans[++cnt]=st[now[0]][now[1]];
		t[0]=now[0]-fx[st[now[0]][now[1]]][0];
		t[1]=now[1]-fx[st[now[0]][now[1]]][1];
		now[0]=t[0];
		now[1]=t[1];
	}
	for(int i=cnt;i>=1;i--){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
