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
		if(lj[x][bi]>=0){//ȥ���׵ı��Ѿ������ڽӱ�����
			le[x]=bi;//�����
			tofa[bi]=lj[x][bi];
			lj[x][bi]=-1;
			lj[bi][x]=-1;
			bt(bi);
			break;
		}
	}
	for(;bi<=n;bi++){
		if(lj[x][bi]>=0){//ȥ���׵ı��Ѿ������ڽӱ����� 
			ri[x]=bi;//�Ҷ���
			tofa[bi]=lj[x][bi];
			lj[x][bi]=-1;
			lj[bi][x]=-1;
			bt(bi);
			return;
		}
	}
	return;
}
int DFS(int x/*��ǰ�ڵ�*/,int y/*�����Ľڵ���*/){
	cnt++;
	if(f[x][y]>=0){//�����ظ� 
		return f[x][y];
	}
	if(y==0){//һ���㲻�� 
		return 0; 
	}
	if(y==1){
		return tofa[x];//ֻ�������� 
	}
	if((le[x]==0)&&(ri[x]==0)){//Ҷ 
		return tofa[x];
	}
	int Dans=0;
	for(int di=0;di<y;di++){ 
		Dans=max(Dans,DFS(le[x],di)+DFS(ri[x],y-di-1));//���������ĵ���֮�ͼ���x�������y 
	}
	f[x][y]=Dans+tofa[x];
	return f[x][y];//���������ֵ�������Ÿ��׵ı�Ȩ 
}
int main(){
	cin>>n>>q/*�����ı���*/; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lj[i][j]=-1;
			f[i][j]=-1;
		}
	}
	for(int i=1;i<n;i++){
		read(); 
	}
	bt(1);//�Խڵ�1Ϊ������(DFS)
	cout<<DFS(1,q+1/*����+1=����*/)<<endl;
	return 0;
}
