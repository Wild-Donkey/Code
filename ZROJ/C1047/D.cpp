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
bitset<10005> E[10005], Neib, NSet, Grop, GSet;
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
    for (unsigned i(1); i <= n; ++i) {
      Neib = NSet = E[i];
      while (NSet.any()) {
        unsigned Pos(NSet._Find_first());
        Grop = GSet = E[Pos] & Neib;
        Grop[Pos] = 1;
        while (GSet.any()) {
          unsigned GNei(GSet._Find_first());
          Grop[GNei] = GSet[GNei] = 0; 
          if((E[GNei] & Neib) != Grop) {Flg = 1;break;}
          Grop[GNei] = 1;
        }
        if(Flg) break;
        NSet ^= Grop;
      }
      if(Flg) break;
    }
    printf(Flg ? "YES\n" : "NO\n");
  }
  return Wild_Donkey;
}
/*

*/
