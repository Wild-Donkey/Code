#include<iostream>
using namespace std;
int n,ans[10005];
void dfs(int x,int y) {//x表示还没有分配的n的数字，y表示当前所决定的最小位置 
	if(x==1){
		ans[y]=1;
		cout<<n<<"="<<ans[1];
		for(int k=2; k<=y ;k++) {
			cout<<"+"<<ans[k];
		} 
		cout<<endl;
	}
	else{
		for(int j=ans[y-1];j<=x/2;j++) {
			ans[y]=j;
			dfs(x-j,y+1);
		}
		ans[y]=x;
		cout<<n<<"="<<ans[1];
		for(int k=2;k<=y;k++) {
			cout<<"+"<<ans[k];
		}
		cout<<endl;
	}
	return;
}
int main() {
	cin>>n;
	for(int i=1;i<=n/2;i++) {
		ans[1]=i;
		dfs(n-i,2);
	}
	return 0;
}
