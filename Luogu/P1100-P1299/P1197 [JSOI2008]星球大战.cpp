#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,fa[400005],s,e,l,k=0,ans=0;
struct side{
	int le,ri;
}a[200005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		cin>>s>>e;
		a[i].le=s;
		a[i].ri=e;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int i=0;
	while(i<=m){
		i++;
		int fa1=find(a[i].le),fa2=find(a[i].ri);
		if(fa1!=fa2){
			ans+=a[i].len;
			fa[fa1]=fa2;
			k++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
