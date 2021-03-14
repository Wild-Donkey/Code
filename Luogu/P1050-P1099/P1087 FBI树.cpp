#include<iostream>
using namespace std;
int n,two[20000];
bool a[20000]={0};
char ch;
int DFS(int x,int y){
	if(x==y){//Ҷ 
		if(a[x]){
			cout<<"I";
			return 2;
		}
		else{
			cout<<"B";
			return 0;
		}
	}
	int dt=0;
	dt=DFS(x,(x+y)/2)+DFS((x+y)/2+1,y);
	if(dt==4){
		cout<<"I";
		return 2;
	}
	if(dt==0){
		cout<<"B";
		return 0; 
	}
	cout<<"F";
	return 1;
}
int main(){
	cin>>n;
	two[0]=1;
	for(int i=1;i<=n;i++){
		two[i]=two[i-1]*2;
	}
	for(int i=1;i<=two[n];i++){
		cin>>ch;
		if(ch=='1'){
			a[i]=1;
		}
	}
	DFS(1,two[n]);
	return 0;
} 
