#include<iostream>
#include<cstring>
using namespace std;
int f[1005][1005],ls,lt; 
string s,t;
void FUCK(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=ls;i++){
		for(int j=1;j<=lt;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(s[i-1]==t[j-1]){
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
	}
	return;
}
int main(){
	while(cin>>s){
		cin>>t;
		ls=s.length();
		lt=t.length();
		FUCK();
		cout<<f[ls][lt]<<endl;
	}
	return 0;
}
