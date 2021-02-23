#include<iostream>
using namespace std;
int n,m,k,a[1005][1005]={0};
int fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
long long  final_ans =1;
char ch;
bool NO=0;
void dfs(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if(NO){
		return;
	}
	a[x][y]=-0x3fff;
	bool ci=0;
	for(int i=0;i<4;i++){
		int dx,dy;
		dx=x+fx[i];
		dy=y+fy[i];
		if((dx>0)&&(dy>0)&&(dx<=n)&&(dy<=m)){
			//cout<<x<<" "<<dx<<" "<<y<<" "<<dy<<" "<<a[dx][dy]<<endl;
			if(a[dx][dy]==2){
				ci=1;
				a[dx][dy]=-0x3fff;
				 final_ans *=(k-1);
				 final_ans %=998244353;
				dfs(dx,dy);
			}
			if(a[dx][dy]==1){
				ci=1;
				a[dx][dy]=-0x3fff;
				 final_ans *=(k-1);
				 final_ans %=998244353;
			}
		}
	}
	if(!ci){
		NO=1;
		return;
	}
	return; 
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='O'){
				for(int k=0;k<4;k++){
					a[i+fx[k]][j+fy[k]]++;
				}
			}
			else{
				a[i][j]=-0x3fff;
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<endl;
		for(int j=1;j<=m;j++){
			//cout<<a[i][j]<<"	"; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				a[i][j]=-0x3fff;
				 final_ans *=k;
				 final_ans %=998244353;
			}
			if(a[i][j]==1){ 
				 final_ans *=k;
				 final_ans %=998244353;
				dfs(i,j);
				if(NO){
					cout<<"0"<<endl;
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<endl;
		for(int j=1;j<=m;j++){
		//	cout<<i<<" "<<j<<" "<<a[i][j]<<"	";
			if(a[i][j]>=0){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	cout<< final_ans <<endl;
	return 0;
}
