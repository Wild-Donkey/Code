#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int n,m,f[105][105][2],fx[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}},now[2],ans[10005][2],cnt=0;
int q[10005][2],l,r;
bool vsd[105][105];
void door(int x,int y){
	r++;
	q[r][0]=x;
	q[r][1]=y;
	return;
}
void BFS(int x,int y){
	vsd[x][y]=1;
	int nx,ny;
	for(int i=0;i<8;i++){
		nx=x+fx[i][0];
		ny=y+fx[i][1];
		if(!vsd[nx][ny]){
			f[nx][ny][0]=x;
			f[nx][ny][1]=y;
			door(nx,ny);
		}
	}
	while(l<=r){//¶Ó²»¿Õ 
		BFS(q[l][0],q[l][1]);
		l++;
	}
	return;
}
int main(){
	//freopen("labyrinth.in","r",stdin);
	//freopen("labyrinth.out","w",stdout);
	cin>>n>>m;
	memset(vsd,1,sizeof(vsd));
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>vsd[i][j];
		}
	}
	BFS(1,1);
	if(f[n][m][0]>=0xffff){
		cout<<-1<<endl;
		return 0;
	}
	now[0]=n;
	now[1]=m;
	ans[++cnt][0]=now[0];
	ans[cnt][1]=now[1];
	while(f[now[0]][now[1]][0]<0xffff){
		int t[2];
		t[0]=f[now[0]][now[1]][0];
		t[1]=f[now[0]][now[1]][1];
		now[0]=t[0];
		now[1]=t[1];
		ans[++cnt][0]=now[0];
		ans[cnt][1]=now[1];
	}
	for(int i=cnt;i>=1;i--){
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}
