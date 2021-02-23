#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,l,r,x,a[5005][5005],b[5005],now,k=1,ans=0;
bool vsd[5005]={0};
void update(int at){
	for(int i=1;i<=n;i++) {
		b[i]=min(a[at][i],b[i]);
	}
	vsd[at]=true;
	return;
}
int find(){
	int ft=0;
	for(int i=1;i<=n;i++){
		if(!vsd[i]){
			if(b[i]<=b[ft]){
				ft=i;
			}
		}
	}
	return ft;
}
int main(){
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>l>>r>>x;
		a[l][r]=min(a[l][r],x);
		a[r][l]=min(a[r][l],x);
	}
	memset(b,0x3f,sizeof(b));
	update(1);
	while(k<n){
		now=find();
		ans+=b[now];
		update(now);
		k++;
	}
	cout<<ans<<endl;
	return 0;
}
