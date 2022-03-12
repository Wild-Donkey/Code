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
bool a[400005];
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
	int val;
	bool tag;
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
void PD(Node *now) {
	//printf("PushDown %d %d %d %d\n",now->L,now->R,now->val,now->tag); 
	if(now->tag==0) {
		return;
	}
	now->tag=0;
	now->val=now->R-now->L+1-now->val;
	if(Leaf(now)) {
		return;
	}
	now->ls->tag=!(now->ls->tag);
	now->rs->tag=!(now->rs->tag);
	return;
}
void UD(Node *now) {
	if(Leaf(now)) {
		return;
	}
	PD(now->ls);
	PD(now->rs);
	now->val=now->ls->val+now->rs->val;
	return;
}
Node *Build(int l,int r) {
	Node *now=cntn++;
	now->L=l;
	now->R=r;
	if(Leaf(now)) {
		now->val =a[now->L];
		now->ls=NULL;
		now->rs=NULL;
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(l,m);
	now->rs=Build(m+1,r);
	UD(now);
	//printf("Build %d %d %d\n",l,r,now->val); 
	return now;
}
int Find(int l,int r,Node *now) {
	//printf("Find %d %d %d %d\n",now->L,now->R,now->val,now->tag); 
	if(Out(l,r,now)) { //不影响
		return 0;
	}
	if(In(l,r,now)) { //全包
		return now->val;
	}
	PD(now);
	UD(now);
	return Find(l,r,now->ls)+Find(l,r,now->rs);
}
void Change(int l,int r,Node *now) {
	if(Out(l,r,now)) {
		return;
	}
	if(In(l,r,now)) {
		now->tag=!(now->tag);
		return;
	}
	PD(now);
	Change(l,r,now->ls);
	Change(l,r,now->rs);
	UD(now);
	return;
}
int main() {
	//freopen("P2574_2.in","r",stdin);
	//freopen("P2574.out","w",stdout);
	n = IN();
	m = IN();
	//printf("n=%d m=%d\n",n,m); 
	memset(a,0,sizeof(a));
	//getchar(); 
	cin>>s;
	for(register int i=1; i<=n; i++) {
		if(s[i-1]=='1') {
			a[i]=1;
		}
	}
	Build(1,n);
	int DoWhat,A,B;
	for(register int i=1; i<=m; i++) {
		DoWhat=IN();
		A=IN();
		B=IN();
		if(DoWhat==1) {
			printf("%d\n",Find(A,B,N));
		} else {
			Change(A,B,N);
		}
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
/*
9 5
101110101
1 1 9
0 1 4
1 1 5
0 1 3
1 3 7
*/
