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
int L,T,O,t, n,A,B,C;
bool flg;
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
	int L,R,cool,taag;
	Node *ls,*rs;
} N[200005],*cntn=N;
bool Out(int l,int r,Node *noow) {
	if((noow->L>r)||(noow->R<l)) {
		return 1;
	}
	return 0;
}
bool Inc(int l,int r,Node *noow) {
	if((noow->L>=l)&&(noow->R<=r)) {
		return 1;
	}
	return 0;
}
bool Leaf(Node *noow) {
	if(noow->L==noow->R) {
		return 1;
	}
	return 0;
}
void PSD(Node *noow) {
	if(noow->taag==0) {
		return;
	}
	noow->cool=noow->taag;
	if(Leaf(noow)) {
		return;
	}
	noow->ls->taag=noow->taag;
	noow->rs->taag=noow->taag;
	//now->ls->col=now->tag;
	//now->rs->col=now->tag;
	noow->taag=0;
	return;
}
void UD(Node *noow) {
	if(Leaf(noow)) {
		return;
	}
	PSD(noow->ls);
	PSD(noow->rs);
	noow->cool=(noow->ls->cool)|(noow->rs->cool);
	return;
}
Node *Build(int l,int r) {
	Node *noow=cntn++;
	noow->L=l;
	noow->R=r;
	noow->cool=2;
	//printf("Build %d %d %d\n",now->L,now->R,now-N);
	if(l==r) {
		noow->ls=NULL;
		noow->rs=NULL;
		return noow;
	}
	int m=(l+r)>>1;
	noow->ls=Build(l,m);
	noow->rs=Build(m+1,r);
	return noow;
}
void Change(int l,int r,int x,Node *noow) {
	//printf("Change %d %d %d %d to\n",now->L,now->R,now->col,now->tag);
	PSD(noow);
	if(Out(l,r,noow)) {
		return;
	}
	if(Inc(l,r,noow)) { //ÑÕÉ«È«ÊÇx
		noow->taag=1<<x;
		//PSD(now);
		return;
	}
	Change(l,r,x,noow->ls);
	Change(l,r,x,noow->rs);
	UD(noow);
	//printf("%d %d %d\n",now->L,now->R,now->col);
	return;
}
int Find(int l,int r,Node *noow) {
	//printf("Find %d %d %d\n",now->L,now->R,now->col);
	PSD(noow);
	if(Out(l,r,noow)) {
		return 0;
	}
	if(Inc(l,r,noow)) {
		//printf("Found %d %d %d\n",now->L,now->R,now->col);
		//PSD(now);
		//UD(now);
		return noow->cool;
	}
	PSD(noow);
	return Find(l,r,noow->ls) | Find(l,r,noow->rs);
}
int Count(int x) {
	int ansc=0;
	for(int i=0; i<=T; i++) {
		if(((1<<i)&x)>0) {
			//printf("%d & %d = %d\n",1<<i,col,(1<<i)&col);
			ansc++;
		}
	}
	return ansc;
}
int main() {
	freopen("P1558_1.in","r",stdin);
	freopen("P1558.out","w",stdout);
	L=IN();
	T=IN();
	O=IN();
	Build(1,L);
	for (register int iI = 1; iI <= O; iI++) {
		ch=getchar();
		A=IN();
		B=IN();
		//printf("do %c %d %d\n",ch,A,B);
		if(A>B) {
			int faq=A;
			A=B;
			B=faq;
		}
		if(ch=='C') {
			C=IN();
			Change(A,B,C,N+0);
		} else {
			int outt=Count(Find(A,B,N+0));
			printf("%d\n",outt);
			//printf("faq %d %d\n",iI,tmpp.Count());
		}
		//getchar();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
100000 30 10
C 1 1500 28
C 1001 2500 20
C 2001 3500 30
C 3001 4500 29
C 4001 5500 27
C 5001 6500 26
C 6001 7500 25
P 6476 4346
P 3643 7543
P 1 27568

3
5
8
*/

