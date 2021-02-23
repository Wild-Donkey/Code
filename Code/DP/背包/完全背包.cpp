#include<iostream>
using namespace std;
long long n,f[10000007]={0},kg[30005],dl[20005];
int main(){
	cin>>kg[0]>>n;
	for(int i=1;i<=n;i++){
		cin>>kg[i]>>dl[i];
	}
	for(int i=1;i<=n;i++){//枚举物品 
		for(int j=1;j<=kg[0];j++){//尝试放入 
			if(j<kg[i]){//放不开 
				f[j]=f[j];//不放 
			}
			else{//放得开 
				f[j]=max(f[j],f[j-kg[i]]+dl[i]);
			}
		}
	}
	cout<<f[kg[0]]<<endl;
	return 0;
}
