#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int la,lb,f[2005][2005];
int main(){
	memset(f,0x3f,sizeof(f));
	cin>>a>>b;
	la=a.length();
	lb=b.length();
	for(int i=0;i<=lb;i++){
		f[0][i]=i;
	}
	for(int i=1;i<=la;i++){
		f[i][0]=i;//边界条件 
	}
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			if(a[i-1]==b[j-1]){
				f[i][j]=min(f[i][j],f[i-1][j-1]);//不动 
			}
			else{
				f[i][j]=min(f[i][j],f[i-1][j-1]+1);
			}
			f[i][j]=min(f[i][j],f[i-1][j]+1);//删
			f[i][j]=min(f[i][j],f[i][j-1]+1);//加 
		}
	}
	cout<<f[la][lb]<<endl; 
	return 0;
}
