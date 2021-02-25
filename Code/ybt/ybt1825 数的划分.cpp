#include<iostream>
using namespace std;
int n,m,ans;
int updi(int x,int y){
	if(x%y){
		return (x/y)+1;
	}
	return x/y;
}
void DFS(int x,int y,int z){
	if(y>=m){
		if(x==n){
			//cout<<y<<endl<<"faq"<<z<<endl; 
			ans++;
		}
		return;
	}
	if((n-x)/(m-y)<=0){
		return;
	}
	for(int i=updi(n-x,m-y);i<=z;i++){
		//cout<<y<<" "<<i<<endl;
		DFS(x+i,y+1,i);
	}
	return;
}
int main(){
	cin>>n>>m;
	DFS(0,0,n-m+1);
	cout<<ans<<endl;
	return 0;
} 
