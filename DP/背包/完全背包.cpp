#include<iostream>
using namespace std;
long long n,f[10000007]={0},kg[30005],dl[20005];
int main(){
	cin>>kg[0]>>n;
	for(int i=1;i<=n;i++){
		cin>>kg[i]>>dl[i];
	}
	for(int i=1;i<=n;i++){//ö����Ʒ 
		for(int j=1;j<=kg[0];j++){//���Է��� 
			if(j<kg[i]){//�Ų��� 
				f[j]=f[j];//���� 
			}
			else{//�ŵÿ� 
				f[j]=max(f[j],f[j-kg[i]]+dl[i]);
			}
		}
	}
	cout<<f[kg[0]]<<endl;
	return 0;
}
