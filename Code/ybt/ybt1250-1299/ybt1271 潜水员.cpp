#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,f[105][105],kg1[10005],kg2[10005],dl[10005];
int main(){
	cin>>kg1[0]>>kg2[0]>>n;
	for(int i=1;i<=n;i++){
		cin>>kg1[i]>>kg2[i]>>dl[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){//Ã¶¾ÙÎïÆ· 
		for(int j=kg1[0];j>=0;j--){
			for(int k=kg2[0];k>=0;k--){
				f[j][k]=min(f[j][k],f[max(j-kg1[i],0)][max(k-kg2[i],0)]+dl[i]);
			}
		}
	}
	cout<<f[kg1[0]][kg2[0]]<<endl;
	return 0;
}
