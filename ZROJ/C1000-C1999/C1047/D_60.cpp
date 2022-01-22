#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
bitset<10005> E[10005], PSet;
unsigned m, n;
unsigned A, B, C, D, t;
unsigned List[500005][2];
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) E[i][j] = 0;
  Flg = 0, n = RD(), m = RD();
}
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  t = RD();
  while (t--) {
    Clr();
    for (unsigned i(1); i <= m; ++i)
      List[i][0] = RD(), List[i][1] = RD(), E[List[i][0]][List[i][1]] = E[List[i][1]][List[i][0]] = 1; 
    for (unsigned i(1); i <= m; ++i) {
      PSet = (E[List[i][0]] & E[List[i][1]]);
//      for (unsigned j(1); j <= n; ++j) putchar(PSet[j] ? '1' : '0'); putchar(0x0A);
      while (PSet.any()) {
        unsigned Pos(PSet._Find_first());
//        printf("Pos %u\n", Pos);
        PSet[Pos] = 0;
//        for (unsigned j(1); j <= n; ++j) putchar(PSet[j] ? '1' : '0'); putchar(0x0A);
//        for (unsigned j(1); j <= n; ++j) putchar(E[Pos][j] ? '1' : '0'); putchar(0x0A);
//        printf("Do %u\n", (PSet & E[Pos])._Find_first());
        if((PSet & E[Pos]) != PSet) {Flg = 1;break;}
      }
      if(Flg) break;
    }
    printf(Flg ? "YES\n" : "NO\n");
  }
  return Wild_Donkey;
}
/*
2
0 5 10
6 7 10

8942 9040 28304
*/
