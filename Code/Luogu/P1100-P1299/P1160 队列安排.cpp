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
int n,m, a[10005], ans = 0,cnt=0,Do1,Do2;
bool flg;
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
struct Node{
	int val;
	Node *l,*r;
}N[100050],*Adr[100050],*cntn=N+1;
void ADDl(int x){
	cnt++;
	cntn++;
	Node *now=Adr[x];
	//printf("ADDl %d %d\n",now->val,x); 
	cntn->r=now;
	cntn->l=now->l;
	if(now->l!=NULL) {
		now->l->r=cntn;
	}
	now->l=cntn;
	cntn->val=cnt;
	Adr[cnt]=cntn;
	//printf("%d %d %d\n",cntn->l->val,cntn->val,cntn->r->val); 
	return;
}
void ADDr(int x){
	cnt++;
	cntn++;
	Node *now=Adr[x];
	//printf("ADDr %d %d\n",now->val,x); 
	cntn->l=now;
	cntn->r=now->r;
	if(now->r!=NULL) {
		now->r->l=cntn;
	}
	now->r=cntn;
	cntn->val=cnt;
	Adr[cnt]=cntn;
	//printf("%d %d %d\n",now->val,cntn->val,cntn->r->val); 
	return;
}
void Del(int x){
	Node *now=Adr[x];
	if(now==NULL){
		return;
	}
	//printf("Del %d %d %d\n",now->l->val,now->val,now->r->val); 
	if(now->r!=NULL) {
		now->r->l=now->l;
	}
	if(now->l!=NULL) {
		now->l->r=now->r;
	}
	Adr[x]=NULL;
	//printf("%d %d\n",now->l->val,now->r->val); 
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
	N[0].val=0;
	N[1].val=0x3f3f3f3f;
	N[0].r=N+1;
	N[1].l=N;
	N[0].l=NULL;
	N[1].r=NULL;
	Adr[0]=N;
	ADDr(0);	
	n = IN();
	for(int i=2;i<=n;i++){
		Do1=IN();
		Do2=IN();
		if(Do2==0){
			ADDl(Do1);
		}
		else{
			ADDr(Do1);
		}
	}
	m=IN();
	for(int i=1;i<=m;i++){
		Do1=IN();
		Del(Do1);
	}
	//printf("%d\n",N[0].val); 
    for(Node *i=N[0].r;i!=N+1;i=i->r){
    	printf("%d ",i->val);
	} 
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

