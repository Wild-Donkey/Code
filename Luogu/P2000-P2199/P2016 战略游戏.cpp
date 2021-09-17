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
int t, n, a[10005], ans = 0,fst[10005],rot;
bool flg;
char ch;
string s;
int IN() {
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
struct Node{
	int n_son,son[1505],num;
	bool IfnoRt; 
	int f[2];
}N[10005];
/*void BT(Node *f,Node *now){
	if(f->fa==NULL){
		ro=f;
	}
	//printf("Build %d %d\n",f-N,now-N); 
	now->fa=f;
	now->ffa=0x3f3f3f3f;
	now->fse=0x3f3f3f3f;
	now->fso=0x3f3f3f3f;
	now->fst=NULL;
	cnted++;
	//printf("%d is %d's fa\n",now->fa-N,now-N); 
	return;
}*/
void DFS(int now){
	//printf("%d\n",now); 
	if(N[now].n_son==0){//叶
		N[now].f[0]=1;//放 
		N[now].f[1]=0;//不放 
		return;
	}
	int tmp=-0x3f3f3f3f,Sum=0;
	N[now].f[0]=0;
	N[now].f[1]=0;
	for(int i=1;i<=N[now].n_son;i++){//遍历子节点 
		DFS(N[now].son[i]);
		N[now].f[0]+=min(N[N[now].son[i]].f[0],N[N[now].son[i]].f[1]);
		N[now].f[1]+=N[N[now].son[i]].f[0];
	}
	N[now].f[0]++;
	return;
}
int main() {
    n = IN();
    for (int i = 1; i <= n; i++) {
      int num_se = IN();
	  N[num_se].n_son = IN();
    	for(int so=1;so<=N[num_se].n_son;so++){
      		N[num_se].son[so]=IN();
      		N[N[num_se].son[so]].IfnoRt=1;
      	//BT(N+num_se,N+sonn);
	  }
	}
	int ii=0;
	while(!N[ii].IfnoRt){
		rot=ii;
		ii++;
	} 
    DFS(rot);
    printf("%d\n", min(N[rot].f[0],N[rot].f[1]));
  return 0;
}
/*
4
0 1 1
1 2 2 3
2 0
3 0

1
*/
