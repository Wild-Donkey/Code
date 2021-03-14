#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[400],Card[5]={0},f[4001][4001];
string s;
int main(){
	cin>>s;
	n=s.length();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[0][i]=0;
		f[1][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int l=0,r=l+len-1;r<n;l++,r++){
			if(s[l]==s[r]){
				f[len][l]=f[len-2][l+1];
			}
			f[len][l]=min(f[len-1][l],min(f[len][l]-1,f[len-1][l+1]))+1;
		}
	}
	cout<<f[n][0]<<endl;
	return 0;
}
