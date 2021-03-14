#include<iostream>
using namespace std;
int n,f[30007]={0},kg[30005],dl[20005];
int main(){
	cin>>n>>kg[0];
	for(int i=1;i<=n;i++){
		cin>>kg[i]>>dl[i];
	}
	for(int i=1;i<=n;i++){//Ã¶¾ÙÎïÆ· 
		for(int j=kg[0];j>=kg[i];j--){
			f[j]=max(f[j],f[j-kg[i]]+dl[i]);
		}
	}
	cout<<f[kg[0]]<<endl;
	return 0;
}
