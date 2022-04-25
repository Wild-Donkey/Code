#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,m;
bool la=0;
int main(){
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n;
		if((n==2)||(n==3)){
			cout<<-1<<endl;
			continue;
		}
		if(n==1){
			cout<<n<<endl;
		}
		m=n/4;
		n%=4;
		for(int i=m;i>=2;i--){
			cout<<(i*4)+n-1<<" "<<(i*4)+n-3<<" "<<(i*4)+n<<" "<<(i*4)+n-2<<" ";
		}
		if(n==0){
			cout<<"3 1 4 2"<<endl;
			continue;
		}
		if(n==1){
			cout<<"4 2 5 3 1"<<endl;
			continue;
		}
		if(n==2){
			cout<<"6 4 2 5 3 1"<<endl;
			continue;
		}
		if(n==3){
			cout<<"7 5 2 6 4 1 3"<<endl;
			continue;
		}
	}
	return 0;
}
