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
int t, n, m, DoWhat,dol,dor,dox;
long long a[300005];
bool flg;
char ch;
string s;
long long IN() {
	char ich = getchar();
	long long intmp = 0, insign = 1;
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
struct Node {
	int L,R;
	long long tagg,val;
	Node *ls,*rs;
} N[300005],*cntnd=N+0;
void PsDo(Node *now){
	//printf("PushDown %d %d %d\n",now->L,now->R,now->tagg); 
	if(now->tagg==0){
		return;
	}
	//printf("%d\n",now->val); 
	now->val+=(now->tagg)*(now->R-now->L+1);
	//printf("%d\n",now->val); 
	if((now->ls!=NULL)&&(now->rs!=NULL)){//非叶 
		now->ls->tagg+=now->tagg;
		now->rs->tagg+=now->tagg;
	}
	now->tagg=0;
	return; 
}
void UD(Node *now){
	if((now->ls!=NULL)&&(now->rs!=NULL)){
		PsDo(now->ls);
		PsDo(now->rs); 
		now->val=now->ls->val+now->rs->val; 
	}
	return; 
}
Node *Build(Node *now,int l,int r){
	//printf("%d %d %d\n",now-N,l,r); 
	now->L=l;
	now->R=r; 
	if(l==r){//叶 
		now->ls=NULL;
		now->rs=NULL;
		now->val=a[l];
		//printf("%d %d %d\n",now->L,now->R,now->val); 
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(++cntnd,l,m);
	now->rs=Build(++cntnd,m+1,r);
	UD(now);
	//printf("%d %d %d %d %d\n",now->ls-N,now->rs-N,now->L,now->R,now->val); 
	return now;
}
long long Find(int fl,int fr,Node *now){
	//printf("%d %d %d %d %d\n",fl,fr,now-N,now->L,now->R); 
	UD(now);
	PsDo(now);
	if((fl<=now->L)&&(fr>=now->R)){//全包含
		return now->val;
	}
	if((fl>now->R)||(fr<now->L)){//不包含
		//printf("NO %d %d %d %d\n",fl,fr,now->L,now->R); 
		return 0; 
	}
	return Find(fl,fr,now->ls)+Find(fl,fr,now->rs);
} 
void Change(int cl,int cr,int cx,Node *now){
	//printf("Change %d %d %d %d %d\n",cl,cr,now->L,now->R,now-N);
	if((cl<=now->L)&&(cr>=now->R)){//全包 
		//printf("All %d %d\n",now->L,now->R); 
		now->tagg+=cx;
		return;
	}
	if((cl>now->R)||(cr<now->L)){//不包 
		//printf("No %d %d\n",now->L,now->R); 
		return; 
	}
	//printf("ls %d %d\n",now->ls->L,now->ls->R); 
	Change(cl,cr,cx,now->ls);
	//printf("rs %d %d\n",now->rs->L,now->rs->R); 
	Change(cl,cr,cx,now->rs);
	UD(now);
	return;
}
int main() {
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n = IN(),m=IN();
	for (int i = 1; i <= n; i++) {
		a[i] = IN();
	}
	Build(N+0,1,n);
	for(int i=1;i<=m;i++){
		DoWhat=IN();
		int tmpp=IN(),tmpmp=IN();
		if(DoWhat==1){//修改 
			Change(tmpp,tmpmp,IN(),N+0); 
		}
		else{
			printf("%lld\n",Find(tmpp,tmpmp,N+0));
		}
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
/*
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

11
8
20

8 3
640 591 141 307 942 58 775 133 
1 4 8 60
2 1 6
2 5 8

**2859**2799**
2148
*/
