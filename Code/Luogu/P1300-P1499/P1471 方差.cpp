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
int t, n,m;
double a[200005];
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
	int L,R;
	double SU,POSU,tag;
	Node *ls,*rs;
} N[200100],*cntn=N;
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
void PD(Node *now) {
	//printf("PushDown [%d,%d] su= %lf posu= %lf tag= %lf\n",now->L,now->R,now->SU,now->POSU,now->tag); 
	if(now->tag==0) {
		return;
	}
	if(Leaf(now)){
		now->tag=0;
		return;
	}
	now->ls->tag+=now->tag;
	now->rs->tag+=now->tag;
	now->ls->POSU+=(2*now->tag*now->ls->SU)+((now->ls->R-now->ls->L+1)*now->tag*now->tag);
	now->ls->SU+=now->tag*(now->ls->R-now->ls->L+1);
	now->rs->POSU+=(2*now->tag*now->rs->SU)+((now->rs->R-now->rs->L+1)*now->tag*now->tag);
	now->rs->SU+=now->tag*(now->rs->R-now->rs->L+1);
	//printf("PushedDown [%d,%d] su= %lf posu= %lf tag= %lf\n",now->L,now->R,now->SU,now->POSU,now->tag);
	now->tag=0;
	return;
}
void UD(Node *now) {
	if(Leaf(now)) {
		return;
	}
	now->SU=now->ls->SU+now->rs->SU;
	now->POSU=now->ls->POSU+now->rs->POSU;
	//printf("POSU Update [%d,%d] %lf+%lf=%lf\n",now->L,now->R,now->ls->POSU,now->rs->POSU,now->POSU); 
	return;
}
Node *Build(int l,int r) {
	Node *now=cntn++;
	now->L=l;
	now->R=r;
	if(Leaf(now)) {
		now->SU=a[l];
		now->POSU=a[l]*a[l];
		now->ls=NULL;
		now->rs=NULL;
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(l,m);
	now->rs=Build(m+1,r);
	UD(now);
	//printf("Build [%d,%d] %lf %lf\n",l,r,now->SU,now->POSU); 
	return now;
}
double Find1(int l,int r,Node *now) {//和 
	if(Out(l,r,now)) { //不影响
		return 0;
	}
	if(In(l,r,now)) { //全包
		return now->SU;
	}
	PD(now);
	double ansf=Find1(l,r,now->ls)+Find1(l,r,now->rs);
	UD(now);
	return ansf;
}
double Find2(int l,int r,Node *now) {//平方和 
	if(Out(l,r,now)) { //不影响
		return 0;
	}
	if(In(l,r,now)) { //全包
		return now->POSU;
	}
	PD(now);
	double ansf=Find2(l,r,now->ls)+Find2(l,r,now->rs);
	UD(now);
	return ansf;
}
void Change(int l,int r,double x,Node *now) {
	if(Out(l,r,now)) {
		return;
	}
	if(In(l,r,now)) {
		now->tag+=x;
		now->POSU+=(2*x*now->SU)+((now->R-now->L+1)*x*x);
		now->SU+=x*(now->R-now->L+1);
		//printf("Maketag [%d,%d] %lf %lf %lf\n",now->L,now->R,now->SU,now->POSU,now->tag); 
		return;
	}
	PD(now);
	Change(l,r,x,now->ls);
	Change(l,r,x,now->rs);
	UD(now);
	//printf("Changed [%d,%d] su=%lf posu=%lf\n",now->L,now->R,now->SU,now->POSU);
	return;
}
int main() {
	//freopen("P1471_1.in","r",stdin);
	//freopen("P2574.out","w",stdout);
	n = IN();
	m = IN();
	for(register int i=1; i<=n; i++) {
		scanf("%lf",&a[i]); 
	}
	Build(1,n);
	int DoWhat,A,B;
	for(register int i=1; i<=m; i++) {
		DoWhat=IN();
		A=IN();
		B=IN();
		if(DoWhat==1) {
			double C;
			scanf("%lf",&C);
			//printf("Change %lf\n",C); 
			Change(A,B,C,N);
		} else {
			double Delta=Find1(A,B,N)/(B-A+1);//平均数 
			if(DoWhat==2){
				printf("%.4lf\n",Delta); 
			}
			else{
				double Deltapo=Delta*Delta;
				printf("%.4lf\n",(Find2(A,B,N)/(B-A+1)-Deltapo));
			}
		}
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
