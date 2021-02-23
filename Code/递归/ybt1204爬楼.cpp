#include<iostream>
using namespace std;
long long fa[35],n; 
int main() {
	fa[1]=1;
	fa[2]=2;
	for(int i=3;i<=30;i++) {
		fa[i]=fa[i-1]+fa[i-2]; 
	}
	while(cin>>n) {
		cout<<fa[n]<<endl;
	}
	return 0;
}
