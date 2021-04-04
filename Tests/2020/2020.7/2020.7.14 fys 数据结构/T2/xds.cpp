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
int t, n, m, dol, dor;
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
inline int G (const int x, const int y) {
	if (y) {
		return G (y, x % y);
	}
	else {
		return x;
	}
}
struct Node {
	int L, R;
	int big, gcd;
	Node *ls,*rs;
} N[300005],*cntnd=N+0;
void UD(Node *now){
	if((now->ls!=NULL)&&(now->rs!=NULL)){
		now->big = max(now->ls->big, now->rs->big);
		now->gcd = G(now->ls->gcd, now->rs->gcd);
	}
	return; 
}
Node *Build(Node *now,int l,int r){
	now->L=l;
	now->R=r; 
	if(l==r){//叶 
		now->ls=NULL;
		now->rs=NULL;
		now->big = a[l];
		now->gcd = a[l];
		//printf("%d %d %d %d\n", now->L, now->R, now->big, now->gcd); 
		return now;
	}
	int m=(l+r)>>1;
	now->ls=Build(++cntnd,l,m);
	now->rs=Build(++cntnd,m+1,r);
	UD(now);
	//printf("%d %d %d %d\n", now->L, now->R, now->big, now->gcd); 
	return now;
}
inline int Findb(int fl,int fr,Node *now){
	if((fl<=now->L)&&(fr>=now->R)){//全包含
		return now->big;
	}
	if((fl>now->R)||(fr<now->L)){//不包含
		return 0;
	}
	return max(Findb(fl,fr,now->ls), Findb(fl,fr,now->rs));
}
inline int Findg(int fl,int fr,Node *now){
	if((fl<=now->L)&&(fr>=now->R)){//全包含
		return now->gcd;
	}
	if((fl>now->R)||(fr<now->L)){//不包含
		return 0; 
	}
	return G (Findg(fl,fr,now->ls), Findg(fl,fr,now->rs));
}
int main() {
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n = IN();
	for (int i = 1; i <= n; i++) {
		a[i] = IN();
	}
	Build(N+0,1,n);
	m = IN();
	for(int i(1);i<=m; ++i){
		int tmpp = IN(),tmpmp=IN();
		//printf("%d %d\n", Findb(tmpp,tmpmp,N+0), Findg(tmpp,tmpmp,N+0)); 
		printf("%d\n",Findb(tmpp,tmpmp,N+0) / Findg(tmpp,tmpmp,N+0));
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
