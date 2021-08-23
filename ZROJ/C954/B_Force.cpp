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
unsigned n;
unsigned K, B, Cnt(0), Ans(0), Tmp(0);
char a[1000005];
inline void Clr() {}
int main() {
  freopen("B.in", "r", stdin);
  freopen("B.ans", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(a + 1, 1, 1000001, stdin);
  for (; a[n + 1] >= 'A'; ++n) a[n] -= 'A';
  a[n] -= 'A';
  for (register unsigned i(1); i <= n; ++i) {
//    printf("%u %u\n", i, a[i]);
    register unsigned Bl(1), Hv(0);
    for (register unsigned k(i); k <= n; ++k) {
      if(a[k] == 0) {
        ++Hv;
      } else {
        if(a[k] == 1) {
          --Bl;
          if(Bl == 0) {
            break;
          }
        } else {
          ++Bl;
        }
      }
    }
    Ans = max(Ans, Hv);
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
2 -1 0
-2 2
*/
