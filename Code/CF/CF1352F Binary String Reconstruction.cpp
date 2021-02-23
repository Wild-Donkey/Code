#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n0,n1,n2;
bool la=0;
int main(){
	cin>>t;
	for(int T=1;T<=t;T++){
		la=0;
		cin>>n0>>n1>>n2;
		if(n2>0){
			for(int i=1;i<=n2+1;i++){
				cout<<1;
			}
		}
		else{
			if(n1<=0){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
		for(int i=1;i<n1;i++){
			cout<<la;
			la=!la;
		}
		if((!la)&&(n1)){//n1ÎªÆæÊý
			cout<<la; 
		}
		for(int i=1;i<=n0;i++){
			cout<<0;
		}
		if(la){
			cout<<1;
		}
		cout<<endl;
	}
	return 0;
}
