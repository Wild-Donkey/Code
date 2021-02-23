#include<iostream>
using namespace std;
int n,q,lj[105][105]={0},tofa[105]={0},le[105]={0},ri[105]={0},cnt=0,f[105][105];
void read(){
	int ra,rb,rc;
	cin>>ra>>rb>>rc;
	lj[ra][rb]=rc;
	lj[rb][ra]=rc;
	return;
}
void bt(int x){
	int bi=1;
	for(;bi<=n;bi++){
		if(lj[x][bi]>=0){//去父亲的边已经不在邻接表里了
			le[x]=bi;//左儿子
			tofa[bi]=lj[x][bi];
			lj[x][bi]=-1;
			lj[bi][x]=-1;
			bt(bi);
			break;
		}
	}
	for(;bi<=n;bi++){
		if(lj[x][bi]>=0){//去父亲的边已经不在邻接表里了 
			ri[x]=bi;//右儿子
			tofa[bi]=lj[x][bi];
			lj[x][bi]=-1;
			lj[bi][x]=-1;
			bt(bi);
			return;
		}
	}
	return;
}
int DFS(int x/*当前节点*/,int y/*保留的节点数*/){
	cnt++;
	if(f[x][y]>=0){//避免重复 
		return f[x][y];
	}
	if(y==0){//一个点不留 
		return 0; 
	}
	if(y==1){
		return tofa[x];//只留它本身 
	}
	if((le[x]==0)&&(ri[x]==0)){//叶 
		return tofa[x];
	}
	int Dans=0;
	for(int di=0;di<y;di++){ 
		Dans=max(Dans,DFS(le[x],di)+DFS(ri[x],y-di-1));//子树保留的点数之和加上x本身等于y 
	}
	f[x][y]=Dans+tofa[x];
	return f[x][y];//子树的最大值加上连着父亲的边权 
}
int main(){
	cin>>n>>q/*保留的边数*/; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lj[i][j]=-1;
			f[i][j]=-1;
		}
	}
	for(int i=1;i<n;i++){
		read(); 
	}
	bt(1);//以节点1为根建树(DFS)
	cout<<DFS(1,q+1/*边数+1=点数*/)<<endl;
	return 0;
}
