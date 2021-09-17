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
int t, n, a[10005], ans = 0,fst[10005];
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
struct Node; 
struct Edge{
	Node *from=NULL,*to=NULL;
	Edge *nxt=NULL;
}E[10005],*cnted=E;
struct Node{
	Node *fa; 
	int ffa,fse,fso;
	Edge *fst;
}N[10005],*ro;
void BT(Node *f,Node *now){
	if(f->fa==NULL){
		ro=f;
	}
	//printf("Build %d %d\n",f-N,now-N); 
	now->fa=f;
	now->ffa=0x3f3f3f3f;
	now->fse=0x3f3f3f3f;
	now->fso=0x3f3f3f3f;
	now->fst=NULL;
	cnted->from=f;
	cnted->nxt=f->fst;
	cnted->to=now;
	f->fst=cnted;
	cnted++;
	//printf("%d is %d's fa\n",now->fa-N,now-N); 
	return;
}
void DFS(Node *now){
	printf("%d\n",now-N); 
	if(now->fst==NULL){//叶
		now->fso=0x3f3f3f3f;//无儿子
		now->fse=1;//靠自己 
		now->ffa=0;//靠爹 
		return;
	}
	int tmp=-0x3f3f3f3f,Sum=0;
	for(Edge *i=now->fst;i!=NULL;i=i->nxt){//遍历子节点 
		DFS(i->to);
		if(i->to->fso>=0x3f3f3f3f){//叶 
			tmp=max(tmp,i->to->ffa-i->to->fse);
			Sum+=i->to->ffa;
		}else{
			tmp=max(tmp,min(i->to->fso,i->to->ffa-i->to->fse));
			Sum+=min(i->to->fso,i->to->ffa);
		}
			now->fse+=min(i->to->ffa,min(i->to->fso,i->to->fse));
			now->ffa+=min(i->to->fse,i->to->fso);
	}
	now->fso=Sum-tmp;
	return;
}
int main() {
    n = IN();
    for (int i = 1; i <= n; i++) {
      int num_se = IN();
	  int num_son = IN();
    	for(int so=1;so<=num_son;so++){
      	int sonn=IN();
      	BT(N+num_se,N+sonn);
	  }
	}
    DFS(ro);
    printf("%d\n", min(ro->fse,ro->fso));
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
