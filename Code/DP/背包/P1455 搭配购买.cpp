#include<iostream>
#include<cstdio>
using namespace std;
int n,m,kg[10005],dl[10005],fa[10005],cnt=0,obj[10005];
long long K[10005],D[10005],kk,f[100005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++){
		cin>>kg[i]>>dl[i];
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		fa[find(a)]=find(b);
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			cnt++;
			obj[i]=cnt;
			K[cnt]=kg[i];
			D[cnt]=dl[i];
		}
	}
	for(int i=1;i<=n;i++){
		int faq=find(i);
		if(faq!=i){
			obj[i]=obj[faq];
			K[obj[i]]+=kg[i];
			D[obj[i]]+=dl[i];
		}
	}
	/*for(int i=1;i<=5000;i++){
		cout<<i<<" "<<find(i)<<endl;
	}/*
	for(int i=1;i<=cnt;i++){
		cout<<i<<" "<<K[i]<<" "<<D[i]<<endl;
	}*/
	for(int i=1;i<=cnt;i++){
		//cout<<i<<" "<<K[i]<<" "<<D[i]<<endl;
		//cout<<kk<<endl;
		for(int j=kk;j>=K[i];j--){
			f[j]=max(f[j],f[j-K[i]]+D[i]);
		}
		/*if(!(i%100)){
			cout<<i<<" "<<f[kk]<<endl;
		}*/
	}
	cout<<f[kk]<<endl;
	return 0;
} 
