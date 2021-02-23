#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,fa[100005],s,e,l,k;
long long ans=0,sum=0;
bool b[100005]={0};
struct side{
	int le,ri,len;
}a[100005];
bool cmp(side x,side y){
	return(x.len>y.len);
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>s;
		b[s]=1;
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n-1;i++){
		cin>>s>>e>>l;
		a[i].le=s;
		a[i].ri=e;
		a[i].len=l;
		sum+=l;
	}
	sort(a+1,a+n,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int i=1;
	while(i<=n-1){
		int fa1=find(a[i].le),fa2=find(a[i].ri);
		if(!(b[fa1]&&b[fa2])){
			if(b[a[i].le]){
				b[a[i].ri]=1;
			}
			if(b[a[i].ri]){
				b[a[i].le]=1;
			}
			ans+=a[i].len;
			fa[fa1]=fa2;
			if(b[fa1]){
			b[fa2]=1;
			}
		}
		i++;
	}
	cout<<sum-ans<<endl;
	return 0;
}
