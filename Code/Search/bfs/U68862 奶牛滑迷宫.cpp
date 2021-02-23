#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int n,m,f[1005][1005],sx,sy,qx[10005],qy[10005],fx[5]={0,1,0,-1,0},fy[5]{0,0,1,0,-1};
bool a[1005][1005],flg=0;
char ch;
string s;
void bfs(int x,int y){
	int l=1;
	int r=1;
	f[x][y]=0;
	qx[r]=x;
	qy[r]=y;
	while(l<=r){
		x=qx[l];
		y=qy[l];
		l++;
		for(int i=1;i<=4;i++){
			int nx=x,ny=y;
			while(!(a[nx+fx[i]][ny+fy[i]])){//²»Åö±Ú 
				nx+=fx[i];
				ny+=fy[i];
				if((nx<=0)||(nx>n)||(ny<=0)||(ny>m)){
					cout<<f[x][y]<<endl;
					flg=1;
					return;
				}
			}
			if((nx<=0)||(nx>n)||(ny<=0)||(ny>m)){
				cout<<f[x][y]<<endl;
				flg=1;
				return;
			}
			if((!(f[nx][ny]))&&(!((nx==sx)&&(ny==sy)))){
				f[nx][ny]=f[x][y]+1;
				//a[nx][ny]=1;
				r++;
				qx[r]=nx;
				qy[r]=ny;
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
	cin>>sx>>sy;
	bfs(sx,sy);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		//	cout<<i<<" "<<j<<" "<<f[i][j]<<"	";
		}
		cout<<endl;
	}*/
	if(!flg){
		cout<<-1<<endl;
	}
	return 0;
}
