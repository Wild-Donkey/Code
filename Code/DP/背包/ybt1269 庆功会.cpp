#include<iostream>
using namespace std;
long long n,f[60005]= {0},kg[20005],dl[20005],cnt=0,two[4]= {1,2,4,8};
bool flg[20005]={0};
void read() {
	int ra,rb,rc;
	cin>>ra>>rb>>rc;
	if(rc==0){
		flg[++cnt]=1;
		kg[cnt]=ra;
		dl[cnt]=rb;
	}
	else{
		for(int i=2; i>=0; i--) {
			if(rc>=two[i+1]-1) {
				rc-=two[i];
				kg[++cnt]=ra*two[i];
				dl[cnt]=rb*two[i];
			}
		}
		if(rc>0) {
			kg[++cnt]=ra*rc;
			dl[cnt]=rb*rc;
		}
	}
}
int main() {
	cin>>kg[0]>>n;
	for(int i=1; i<=n; i++) {
		read();
	}
	for(int i=1; i<=cnt; i++) { //枚举物品
		if(flg[i]){//无限 
			for(int j=kg[i];j<=kg[0];j++){
				f[j]=max(f[j],f[j-kg[i]]+dl[i]);
			}
		}
		else{//有限 
			for(int j=kg[0]; j>=kg[i]; j--) { //尝试放入
				f[j]=max(f[j],f[j-kg[i]]+dl[i]);
			}
		}
	}
	cout<<f[kg[0]]<<endl;
	return 0;
}
