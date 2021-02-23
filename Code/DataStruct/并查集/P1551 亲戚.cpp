#include<iostream>
using namespace std;
int fa[5005],n,m,p,a,b;
int find(int x){
	if(fa[x]==x){
		return x; 
	}
	return find(fa[x]);
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		fa[find(a)]=find(b);
	}
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		if(find(a)==find(b)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
