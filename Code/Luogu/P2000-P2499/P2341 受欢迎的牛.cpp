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
	ndfs[x]=npt;//��¼������dfs��
	nstc++;
	stc[nstc]=x;
	back[x]=ndfs[x];//��ʼ��back 
	int di=first[x];//�� 
	while(di){
		if(!ndfs[ed[di].to]){//δ�� 
			dfs(ed[di].to);
			back[x]=min(back[x],back[ed[di].to]);
		}
		else{
			//cout<<ed[di].to<<" "<<slf[ed[di].to]<<endl;
			if(!slf[ed[di].to]){//���˵���δ��ջ����������һǿ��ͨ������ 
				back[x]=min(back[x],ndfs[ed[di].to]);//����ͨ��di�����ǲ����ѣ��Ѿ����ˣ� 
			}
		}
		di=ed[di].nxt;
	}
	//cout<<x<<" "<<back[x]<<" "<<ndfs[x]<<endl;
	if(back[x]==ndfs[x]){//��Ϊǿ��ͨ�������������������޷�ȥ�κα��Լ�dfs��С�ĵ�
		nslf++;
		slf[x]=nslf;//���x����ǿ��ͨ���� 
		while(stc[nstc]!=x){
			slf[stc[nstc]]=nslf;
			//cout<<stc[nstc]<<" "<<slf[stc[nstc]]<<endl;
			nstc--;//���γ�ջ 
		}
		nstc--;//x��ջ 
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
	for(int i=1;i<=n;i++){//���� 
		if(!ndfs[i]){//δ�� 
			dfs(i); 
		} 
	}
	for(int i=1;i<=ned;i++){//�ؽ��� 
		if(slf[ed[i].from]!=slf[ed[i].to]){//����ͬһ��ǿ��ͨ���� 
			rebuild(slf[ed[i].from],slf[ed[i].to]);
		}
	}
	for(int i=1;i<=nslf;i++){
		if(!nfirst[i]){//����Ϊ�� 
			if(!ans){
				ans=i;
			}
			else{//���������ϳ���Ϊ����û��ţ�������� 
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
