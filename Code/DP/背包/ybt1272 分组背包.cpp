#include<iostream>
using namespace std;
int n,f[10005]={0},kg[15][10005]/*第i组的第j个的质量*/,dl[15][10005]/*同理*/,cnt[15]={0}/*第i组的物品数*/;
void read(){
	int ra,rb,rc;
	cin>>ra>>rb>>rc;
	kg[rc][++cnt[rc]]=ra;
	dl[rc][cnt[rc]]=rb;
	return;
}
int main(){
	cin>>kg[0][0]>>n>>cnt[0];
	for(int i=1;i<=n;i++){
		read();
	}
	for(int i=1;i<=cnt[0];i++){//枚举组 
		for(int k=kg[0][0];k>=0;k--){//枚举质量 
			for(int j=1;j<=cnt[i];j++){//枚举物品
				if(kg[i][j]<=k){ 
					f[k]=max(f[k]/*不拿*/,f[k-kg[i][j]]+dl[i][j]/*拿*/);
				}
			}
		}
	}
	cout<<f[kg[0][0]]<<endl;
	return 0;
}
