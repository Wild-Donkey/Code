#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,a[30][30],cl[30]={0};
bool vsd[30];
string s;
int gtnb(int &x){
	if(s[x]==' '){
		x++;
	}
	int gn=0;
	while((s[x]<='9')&&(s[x]>='0')){
		gn*=10;
		gn+=s[x++]-'0';
	}
	return gn;
}
void DFS(int x){
	vsd[x]=1;
	bool tp[5]={0};
	for(int i=1;i<=n;i++){
		if((vsd[i])&&(a[x][i]==1)){
			tp[cl[i]]=1;
		}
	}
	for(int i=1;i<=4;i++){
		if(!tp[i]){
			cl[x]=i;
			cout<<cl[x]<<" "; 
			return;
		}
	}
	return;
}
int main(){
	//freopen("map.in","r",stdin);
	//freopen("map.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=-1;
		}
	}
	getline(cin,s); 
	for(int i=1;i<=n;i++){
		getline(cin,s);
		int j=0;
		gtnb(j);
		while(j<s.length()){
			int MotherFucker=gtnb(j);
			a[i][MotherFucker]=1;
			a[MotherFucker][i]=1;
			j++;
		}
	}
	for(int i=1;i<=n;i++){ 
		DFS(i);
	}
	cout<<endl;
	return 0;
}
