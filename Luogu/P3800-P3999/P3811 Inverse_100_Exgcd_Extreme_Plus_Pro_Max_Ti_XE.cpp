#include <cstdio>
#include <cctype>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0);
int A, B, C, D, p, a_b[105], Tmp(0);
bool b[105];
inline void Clr() {}
char _d[100000],*_p=_d;
inline void write(register int x){
	static int _q[35];
  register char _t=0; // _q ÊÇÒ»¸öÕ»
	do{_q[_t++]=x%10,x/=10;}while(x);
	while(_t){
		register char c=_q[--_t]+48;
		if(_p-_d==100000)fwrite(_d,1,100000,stdout),_p=_d;
		*_p++=c;
	}
	if(_p-_d==100000)fwrite(_d,1,100000,stdout),_p=_d;
	*_p++='\n';
}
signed main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
//   freopen("FAQ.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  p = RD();
  for (register unsigned i(1); i <= n; ++i) {
    C = p;
    D = i;
    Cnt = 0;
    while(D) {
      a_b[++Cnt] = C / D;
      Tmp = C;
      C = D;
      D = Tmp % D;
    }
    A = 1;
    B = 0;
    for (register unsigned short j(Cnt); j >= 1; --j) {
      Tmp = A;
      A = B;
      B = Tmp - a_b[j] * A;
    }
    B %= p;
    B += p;
    B %= p;
    write(B);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  fwrite(_d,1,_p-_d,stdout);
  return Wild_Donkey;
}
/*
3000000 20000527
*/
