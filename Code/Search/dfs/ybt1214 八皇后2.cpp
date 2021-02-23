#include<iostream>
#include<cstdio>
using namespace std;
int num=0,c,n,ans[100][30];
bool a[30][30]={0},b[30][30]={0};
void record() {
	++num;
	for(int i=1;i<=8;i++) { 
		for(int j=1;j<=8;j++)
			if(a[i+10][j+10])
				ans[num][j+10]=i;
	}
	return;
}
void dfs(int x,int y) {//x是行,y是列 
	a[x+10][y+10]=1;
	if(y==8) { 
		record();
		a[x+10][y+10]=0;
		return; 
	}
	bool z[30][30]={0};
	for(int k=1;y+k<=8;k++) {
		z[x+10][y+k+10]=b[x+10][y+k+10];
		z[x+k+10][y+k+10]=b[x+k+10][y+k+10];
		z[x-k+10][y+k+10]=b[x-k+10][y+k+10];
		b[x+10][y+k+10]=1;
		b[x+k+10][y+k+10]=1;
		b[x-k+10][y+k+10]=1;
	}
	for(int k=1;k<=8;k++) {
		if(!(b[k+10][y+11])) {
			dfs(k,y+1);
		}
	}
	for(int k=1;y+k<=8;k++) {
		b[x+10][y+k+10]=z[x+10][y+k+10];
		b[x+k+10][y+k+10]=z[x+k+10][y+k+10];
		b[x-k+10][y+k+10]=z[x-k+10][y+k+10];
	}
	a[x+10][y+10]=0;
	return;
}
int main() {
	cin>>n;
	for(int l=1;l<=8;l++)
		dfs(l,1);
	for(int m=1;m<=n;m++) {
		cin>>c;
		for(int o=1;o<=8;o++)
			cout<<ans[c][o+10];
		cout<<endl; 
	}
	return 0; 
} 
