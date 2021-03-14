//#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;
int t, n,m,q;
unsigned int a[100050], b[100050],Ans = 0;
bool flg=0;
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
struct Node {
	int L,R,va,vb;
	bool Fl;
	Node *ls,*rs;
} N[400100],*cntn=N;
bool Leaf(Node *noo) {
	if(noo->L==noo->R) {
		return 1;
	}
	return 0;
}
bool In(int l,int r,Node *noo) {
	if((noo->L>=l)&&(noo->R<=r)) {
		return 1;
	}
	return 0;
}
bool Out(int l,int r,Node *noo) {
	if((noo->L>r)||(noo->R<l)) {
		return 1;
	}
	return 0;
}
void UD(Node *now) {
	if(Leaf(now)) {
		return;
	}
	if((now->ls->Fl||now->rs->Fl)/*有儿子不合法*/||((now->ls->vb&now->rs->vb)/*有效位*/&(now->ls->va^now->rs->va)/*不同位*/)){
		now->Fl=1;
		return; 
	}
	now->vb=now->ls->vb|now->rs->vb;
	now->va=now->ls->va|now->rs->va;
	return;
}
Node *Build(int l,int r) {
	Node *now=cntn++;
	now->L=l;
	now->R=r;
	now->Fl=0;
	if(Leaf(now)) {
		now->va=a[l];
		now->vb=b[l];
		now->ls=NULL;
		now->rs=NULL;
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(l,m);
	now->rs=Build(m+1,r);
	UD(now); 
	return now;
}
int Count(unsigned int x){
	if(flg){
		return 0;
	}
	int anss=1;
	x=~x;
	for(register int i=1;i<=n;i++){
		if((x&(1<<i))>0){
			anss=anss<<1;
		}
	}
	return anss;
}
Node *Find(int l,int r,Node *now) {
	cntn++;
	Node *Now=cntn;
	Now->ls=NULL;
	Now->rs=NULL;
	Now->R=now->R;
	Now->L=now->L;
	Now->va=0;
	Now->va=0;
	Now->Fl=0;
	if(flg||Out(l,r,Now)){//已经不合法或不影响
		Now->Fl=1;
		return Now;
	}
	if(In(l,r,now)){//全包 
		if(now->Fl){//不合法
			flg=1;
			return Now;
		}
		Now->va=now->va;
		Now->vb=now->vb; 
		return Now;
	}
	Now->ls=Find(l,r,now->ls);
	Now->rs=Find(l,r,now->rs);//开始合并
	UD(Now);
	/*if(Now->Fl){
		Now->va=0;
		Now->vb=0;
	}*/
	return Now;
}
void Change(int at,string ass,Node *now) {
	if(Leaf(now)) {
		if(now->L==at) {
			now->va=0;
			now->vb=0;
			for(register int i=0; i<n; i++) {
				if(ass[i]!='?') {
					now->vb|=1<<i;
					if(ass[i]=='1') {
						now->va|=1<<i;
					}
				}
			}
		}
		return;
	}
	if(at<=now->ls->R){
		Change(at,ass,now->ls);
	}
	else{
		Change(at,ass,now->rs);
	}
	UD(now);
	return;
}
int main() {
	freopen("P5522_2.in","r",stdin);
	// freopen(".out","w",stdout);
	//	int nima=~((~0)&(~5));
	//	printf("nima%d\n",nima); 
	n = IN();
	m = IN();
	q = IN();
	for (register int i = 1; i <= m; i++) {
		//printf("IN %d\n",i);
		while((ch!='0')&&(ch!='1')&&(ch!='?')) {
			//printf("Fak %c\n",ch); 
			ch=getchar();
		}
		int ini=0;
		while((ch=='0')||(ch=='1')||(ch=='?')) {
			//printf("Lice %c\n",ch); 
			if(ch!='?') {
				b[i]|=1<<ini;
				if(ch=='1') {
					a[i]|=1<<ini;
				}
			}
			//printf("%o %o\n",a[i],b[i]); 
			ch=getchar(); 
			ini++;
		}
	}
	Build(1,m);
	int DoWhat,A,B;
	//printf("q %d\n",q); 
	for(register int i=1; i<=q; i++) {
		flg=0;
		//printf("i %d\n",i);
		DoWhat=IN();
		A=IN();
		//printf("do %d %d\n",DoWhat,A); 
		if(DoWhat==0) {
			B=IN();
			cntn=N+(m<<1)+100;
			int co=Count(Find(A,B,N)->vb);
			//printf("Found %d^%d=%lld\n",Ans,co,Ans^co);
			Ans=Ans^co;
		} else {
			cin>>s;
			//printf("LOOK %d %d %s\n",DoWhat,A,"s"); 
			Change(A,s,N);
		}
	}
	printf("%lld\n",Ans); 
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}

