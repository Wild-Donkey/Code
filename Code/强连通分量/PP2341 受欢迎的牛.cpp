#include<iostream>
using namespace std;
int n,m,ned=0,nned=0,npt=0,nstc=0,nslf=0,first[10005],nfirst[10005],slf[10005],ndfs[10005],back[10005],stc[10005],sum=0,ans=0;
struct edge{
	int from,to,nxt;
}ed[50005],newd[50005];
void build(int x,int y){
	ned++;
	ed[ned].from=x;
	ed[ned].to=y;
	if(first[x]){
		ed[ned].nxt=first[x];
	}
	first[x]=ned;
	return;
}
void rebuild(int x,int y){
	nned++;
	newd[nned].from=x;
	newd[nned].to=y;
	if(nfirst[x]){
		newd[nned].nxt=nfirst[x];
	}
	nfirst[x]=nned;
	return;
}
void dfs(int x){
	npt++;
	ndfs[x]=npt;//纪录点数和dfs序
	nstc++;
	stc[nstc]=x;
	back[x]=ndfs[x];//初始化back 
	int di=first[x];//边 
	while(di){
		if(!ndfs[ed[di].to]){//未搜 
			dfs(ed[di].to);
			back[x]=min(back[x],back[ed[di].to]);
		}
		else{
			//cout<<ed[di].to<<" "<<slf[ed[di].to]<<endl;
			if(!slf[ed[di].to]){//搜了但是未出栈（不属于任一强连通分量） 
				back[x]=min(back[x],ndfs[ed[di].to]);//可以通往di，但是不能搜（已经搜了） 
			}
		}
		di=ed[di].nxt;
	}
	//cout<<x<<" "<<back[x]<<" "<<ndfs[x]<<endl;
	if(back[x]==ndfs[x]){//作为强连通分量搜索树的树根，无法去任何比自己dfs序小的点
		nslf++;
		slf[x]=nslf;//标记x所属强连通分量 
		while(stc[nstc]!=x){
			slf[stc[nstc]]=nslf;
			//cout<<stc[nstc]<<" "<<slf[stc[nstc]]<<endl;
			nstc--;//依次出栈 
		}
		nstc--;//x出栈 
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t;
		cin>>f>>t;
		build(f,t); 
	}
	for(int i=1;i<=n;i++){//缩点 
		if(!ndfs[i]){//未搜 
			dfs(i); 
		} 
	}
	for(int i=1;i<=ned;i++){//重建树 
		if(slf[ed[i].from]!=slf[ed[i].to]){//不在同一个强连通分量 
			rebuild(slf[ed[i].from],slf[ed[i].to]);
		}
	}
	for(int i=1;i<=nslf;i++){
		if(!nfirst[i]){//出度为零 
			if(!ans){
				ans=i;
			}
			else{//两个或以上出度为零则没有牛符合条件 
				cout<<0<<endl;
				return 0;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<slf[i]<<endl;
		if(slf[i]==ans){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
