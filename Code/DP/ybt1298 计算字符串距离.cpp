#include<iostream>
#include<cstring>
using namespace std;
int n,f[1005][1005],ls,lt; 
string s,t;
void FUCK(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=ls;i++){
		f[i][0]=i;
	}
	for(int i=1;i<=lt;i++){
		f[0][i]=i;
	}
	for(int i=1;i<=ls;i++){
		for(int j=1;j<=lt;j++){
			if(s[i-1]==t[j-1]){
				f[i][j]=f[i-1][j-1];
			}
			else{
			f[i][j]=min(f[i-1][j-1]+1,min(f[i-1][j]+1,f[i][j-1]+1));
			}
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		cin>>t;
		ls=s.length();
		lt=t.length();
		if(ls<lt){//±£Ö¤ls³¤ 
			string fa;
			fa=t;
			t=s;
			s=fa;
			ls=s.length();
			lt=t.length();
		} 
		FUCK();
		cout<<f[ls][lt]<<endl;
	}
	return 0;
}
