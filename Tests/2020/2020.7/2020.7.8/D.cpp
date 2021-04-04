#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int n, m, k, ans = 0, fx[4][2]={1,0,0,1,0,-1,-1,0};
bool qp[505][505], flg;
char ch;
string s;
inline int IN() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
void Dfs(int x, int y,bool faq) {
	//printf("%d %d\n",x,y); 
	int xx,yy;
	bool fl=0;
	for(int i=0;i<4;i++){
		xx=x+fx[i][0];
		yy=y+fx[i][1];
		if(!qp[xx][yy]){
			qp[xx][yy]=1;
			Dfs(xx,yy,!faq);
			qp[xx][yy]=0;
			fl=1;
		}
	}
	if(!fl){
		if(faq){//dacongzoubuliao
			flg=0;
		}
	}
	return;
}
int main() {
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
    n = IN();
    m = IN();
	k = IN();
	memset(qp, 1, sizeof(qp));
	for(register int i=1; i<=n; i++){
		for(register int j=1; j<=m; j++){
			qp[i][j]=0;
		}
	}
    for (register int i = 1; i <= k; i++) {
    	int aa=IN(),bb=IN();
    	qp[aa][bb]=1;
    }
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		if(!qp[i][j]) { 
    			flg=1;
    			qp[i][j]=1;
    			Dfs(i,j,1);
    			if(flg){
    				ans++;
    			}
    			qp[i][j]=0;
			}
		}
	}
	printf("%d\n",ans); 
	fclose(stdin);
	fclose(stdout);
  return 0;
}
/*
3 3 3
1 1
2 2
3 3

2
*/
