#include <cstdio>
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
unsigned m, n, Cnt(0), t, Ans(0), Tmp(0);
int A, B, C, D, p, a_b[105];
bool b[105];
inline void Clr() {}
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
    for (register unsigned j(Cnt); j >= 1; --j) {
      Tmp = A;
      A = B;
      B = Tmp - a_b[j] * A;
    }
    B %= p;
    B += p;
    B %= p;
    printf("%d\n", B);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3000000 20000527
*/
