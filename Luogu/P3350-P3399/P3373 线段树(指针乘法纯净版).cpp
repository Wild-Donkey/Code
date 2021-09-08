#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, DoWhat,p;
int a[200005];
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
struct Node {
	int L,R;
	long long tag_plus,tag_times,val;//只要Times还在, 就是先Times再Plus 
	Node *ls,*rs;
} N[200005],*cntnd=N+0;
void PsDo_Times(Node *now){
	if(now->tag_times==1){
		return;
	}
	now->val*=(now->tag_times);
	now->val%=p;
	if((now->ls!=NULL)&&(now->rs!=NULL)){
		now->ls->tag_times*=now->tag_times;
		now->rs->tag_times*=now->tag_times;//对Tag_Times操作 
		now->ls->tag_times%=p;
		now->rs->tag_times%=p;
		now->ls->tag_plus*=now->tag_times; 
		now->rs->tag_plus*=now->tag_times;//Tag_Plus的操作 
		now->ls->tag_plus%=p;
		now->rs->tag_plus%=p;
	}
	now->tag_times=1;
	return; 
}
void PsDo_Plus(Node *now){
	//PsDo_Times(now);
	if(now->tag_plus==0){
		return;
	}
	now->val+=(now->tag_plus)*(now->R-now->L+1);//tag记录的是对val的操作, 加入val后就能让Plus和Times独立(先Times再Plus)
	now->val%=p;
	if((now->ls!=NULL)&&(now->rs!=NULL)){
		now->ls->tag_plus+=now->tag_plus;
		now->rs->tag_plus+=now->tag_plus;
		now->ls->tag_plus%=p;
		now->rs->tag_plus%=p;
	}
	now->tag_plus=0;
	return; 
}
void UD(Node *now){
	if((now->ls!=NULL)&&(now->rs!=NULL)){
		PsDo_Times(now->ls);
		PsDo_Plus(now->ls); 
		PsDo_Times(now->rs);//PushDown_Times已经将对Tag_Plus的操作执行完了
		PsDo_Plus(now->rs);
		now->val=(now->ls->val+now->rs->val)%p; 
	}
	//Print(N);
	return; 
}
Node *Build(Node *now,int l,int r){
	now->L=l;
	now->R=r; 
	now->tag_plus=0;
	now->tag_times=1; 
	if(l==r){
		now->ls=NULL;
		now->rs=NULL;
		now->val=a[l];
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(++cntnd,l,m);
	now->rs=Build(++cntnd,m+1,r);
	UD(now);
	return now;
}
long long Find(int fl,int fr,Node *now){
	if((fl>now->R)||(fr<now->L)){
		return 0; 
	}
	PsDo_Times(now);//父节点的Tag能通过影响儿子的Tag, 但儿子的Tag只能通过UD()来影响父亲的val 
	PsDo_Plus(now);//和UD()的情况一样, 先Times再Plus 
	UD(now);
	now->val%=p;
	if((fl<=now->L)&&(fr>=now->R)){
		if((now->ls!=NULL)&&(now->rs!=NULL)){//非叶 
		}
		return now->val;
	}
	return (Find(fl,fr,now->ls)+Find(fl,fr,now->rs))%p;
}
void Change_Plus(int cl,int cr,int cx,Node *now){
	if((cl>now->R)||(cr<now->L)){
		return; 
	}
	if((cl<=now->L)&&(cr>=now->R)){
		now->tag_plus+=cx;
		return;
	}
	PsDo_Times(now);//父节点的Tag能通过影响儿子的Tag, 但儿子的Tag只能通过UD()来影响父亲的val 
	PsDo_Plus(now);//和UD()的情况一样, 先Times再Plus 
	Change_Plus(cl,cr,cx,now->ls);
	Change_Plus(cl,cr,cx,now->rs);
	UD(now);//更新 
	return;
} 
void Change_Times(int cl,int cr,int cx,Node *now){ 
	if((cl<=now->L)&&(cr>=now->R)){
		now->tag_plus*=cx;//Times对之前的Plus有效 
		now->tag_times*=cx;
		now->tag_times%=p;
		return;
	}
	if((cl>now->R)||(cr<now->L)){
		return; 
	}
	PsDo_Times(now);//父节点的Tag能通过影响儿子的Tag, 但儿子的Tag只能通过UD()来影响父亲的val 
	PsDo_Plus(now);//和UD()的情况一样, 先Times再Plus 
	Change_Times(cl,cr,cx,now->ls);
	Change_Times(cl,cr,cx,now->rs);
	UD(now);
	return;
}
int main() {
	n = IN(),m=IN(),p=IN();
	for (register int i = 1; i <= n; i++) {
		a[i] = IN();
	}
	Build(N+0,1,n);
	for(register int i=1;i<=m;i++){
		DoWhat=IN();
		int tmpp=IN(),tmpmp=IN();
		if(DoWhat==1){ 
			Change_Times(tmpp,tmpmp,IN(),N+0); 
		}
		else{
			if(DoWhat==2){
				Change_Plus(tmpp,tmpmp,IN(),N+0);
			}
			else{
				printf("%lld\n",Find(tmpp,tmpmp,N+0));
			}
		}
	}
	return 0;
}
