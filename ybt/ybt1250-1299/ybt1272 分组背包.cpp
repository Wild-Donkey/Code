#include<iostream>
using namespace std;
int n,f[10005]={0},kg[15][10005]/*��i��ĵ�j��������*/,dl[15][10005]/*ͬ��*/,cnt[15]={0}/*��i�����Ʒ��*/;
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
	for(int i=1;i<=cnt[0];i++){//ö���� 
		for(int k=kg[0][0];k>=0;k--){//ö������ 
			for(int j=1;j<=cnt[i];j++){//ö����Ʒ
				if(kg[i][j]<=k){ 
					f[k]=max(f[k]/*����*/,f[k-kg[i][j]]+dl[i][j]/*��*/);
				}
			}
		}
	}
	cout<<f[kg[0][0]]<<endl;
	return 0;
}
