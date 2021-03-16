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
long long t, n, a[10005], heal, mn, nn;
bool flg;
char ch;
string s;
struct Mons {
	long long hel, medi, mnum;
}M[100005],N[100005];
bool cmpm (Mons x, Mons y) {
	return x.hel < y.hel;
}
bool cmpn (Mons x, Mons y) {
	return x.medi > y.medi;
}
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
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = IN();
    heal = IN();
    int inhe, inme;
    for (register int i = 1; i <= n; i++) {
    	inhe = IN();
    	inme = IN();
    	if(inhe <= inme) {//Ñª°ü 
    		mn ++;
    		M[mn].hel = inhe;
			M[mn].medi = inme;
			M[mn].mnum = i;
		}
    	else{//ÏûºÄ 
    		nn ++;
    		N[nn].hel = inhe;
			N[nn].medi = inme;
			N[nn].mnum = i;
		}
	}
    sort (M + 1, M + mn + 1, cmpm);
	sort (N + 1, N + nn + 1, cmpn);
    for (register int i = 1; i <= mn; i++) {
    	heal -= M[i].hel;
    	//printf("%d %d\n", heal, M[i].mnum);
    	if(heal <= 0) {
    		printf("NIE\n");
    		return 0;
		}
		heal += M[i].medi;
	}
	for (register int i = 1; i <= nn; i++) {
		heal -= N[i].hel;
    	//printf("%d %d\n", heal, N[i].mnum);
    	if(heal <= 0) {
    		printf("NIE\n");
    		return 0;
		}
		heal += N[i].medi;
	}
	printf("TAK\n");
	for(register int i = 1; i <= mn; i++) {
		printf("%d ", M[i].mnum);
	}
	for(register int i = 1; i <= nn; i++) {
		printf("%d ", N[i].mnum);
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

