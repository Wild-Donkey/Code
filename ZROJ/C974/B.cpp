#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, CntA(0), CntP(0), Now(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[10005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 10002, stdin);
  n = strlen(a + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if (a[i] == 'A') ++Now, ++CntA;
    if (a[i] == 'P') Ans += (Now ? 1 : 0), Now -= (Now ? 1 : 0), ++CntP;
  }
  printf("%u\n", CntA + CntP - (Ans << 1) - (((CntP - Ans) >> 1) << 1));
  system("pause");
  return Wild_Donkey;
}
/*
PPPPPPPPAPAPAPAPAPAPPAPAPAAPAPAPPAPAPAPAPAPAPAPAPAPAPAPPAPAPAPAPPAPAPAPPAPAPPAPAPAPAPAPPAPAPAAAAAAAAA
*/