#include<iostream>
using namespace std;
int n,a,tmp,ans[1005],cnt,po,k;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>k;
		if(k==1){
			cout<<"YES"<<endl<<a<<endl;
			continue;
		}
		if(k>a){
			cout<<"NO"<<endl;
			continue;
		}
		tmp=a/k;
		a%=k;
		if(a%2){//奇数
			if(!(k%2)){//偶数个数 
				cout<<"NO"<<endl;
				continue;
			}
			tmp--;
			a+=k;
			if(tmp<1){
				cout<<"NO"<<endl;
				continue;
			}
			cout<<"YES"<<endl;
			for(int j=1;j<=a/2;j++){
				cout<<tmp+2<<" ";
			}
			for(int j=a/2+1;j<=k;j++){
				cout<<tmp<<" ";
			}
			cout<<endl;
			continue;
		}
		else{//偶数
			if(tmp<1){
				cout<<"NO"<<endl;
				continue;
			}
			cout<<"YES"<<endl;
			for(int j=1;j<=a/2;j++){
				cout<<tmp+2<<" ";
			}
			for(int j=a/2+1;j<=k;j++){
				cout<<tmp<<" ";
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}
