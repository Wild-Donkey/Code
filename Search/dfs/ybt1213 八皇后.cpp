#include<iostream>
#include<cstdio>
using namespace std;
int num=0;
bool a[30][30]={0},b[30][30]={0};
void print() {
	printf("No. %d\n",++num);
	for(int i=1;i<=8;i++) { 
		for(int j=1;j<=8;j++)
			printf("%d ",int(a[i+10][j+10]));
		printf("\n");
	}
	return;
}
void dfs(int x,int y) {//x是行,y是列 
	a[x+10][y+10]=1;
	if(y==8) { 
		print();
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
	for(int l=1;l<=8;l++)
		dfs(l,1);
	return 0; 
} 
