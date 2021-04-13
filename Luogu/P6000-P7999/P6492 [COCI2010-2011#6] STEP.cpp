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
bool a[200005];
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
	int vall,valr,val;
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
	now->val=max(now->ls->val,now->rs->val);
	now->vall=now->ls->vall;
	now->valr=now->rs->valr;
	if(a[now->ls->R]!=a[now->rs->L]){
		now->val=max(now->ls->valr+now->rs->vall,now->val);
		if(now->ls->vall==now->ls->R-now->ls->L+1){//左儿子整个合法 
			now->vall=now->val; 
		}
		if(now->rs->valr==now->rs->R-now->rs->L+1){//同上 
			now->valr=now->val;
		}
	}
	return;
}
Node *Build(int l,int r) {
	Node *now=cntn++;
	now->val =1;
	now->vall=1;
	now->valr=1;
	now->L=l;
	now->R=r;
	if(Leaf(now)) {
		now->ls=NULL;
		now->rs=NULL;
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(l,m);
	now->rs=Build(m+1,r);
	//printf("Build %d %d %d\n",l,r,now->val); 
	return now;
}
void Change(int x,Node *now) {
	if(Leaf(now)){
		return;
	}
	if(x<=now->ls->R){
		Change(x,now->ls);
	}
	else{
		Change(x,now->rs);
	}
	UD(now);
	return;
}
int main() {
	//freopen("P2574_2.in","r",stdin);
	//freopen("P2574.out","w",stdout);
	n = IN();
	m = IN();
	Build(1,n);
	memset(a,0,sizeof(a));
	int DoWhat,A,B;
	for(register int i=1; i<=m; i++) {
		A=IN();
		a[A]=!a[A];
		Change(A,N);
		printf("%d\n",max(max(N->val,N->vall),N->valr));
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
