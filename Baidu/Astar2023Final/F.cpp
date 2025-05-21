#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
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
unsigned long long C;
unsigned m, n;
unsigned A, B, D, t;
unsigned long long Max[30][105][105], Min[30][105][105], Tmp[2][105],
    LastTmp[2][105];
char Acc[30][105][105], AcT[105], LAcT[105];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD();
  memset(Max, 0, sizeof(Max));
  memset(Min, 0x3f, sizeof(Min));
  for (unsigned i(1); i <= m; ++i) {
    unsigned long long *I;
    A = RD(), B = RD(), C = RD();
    Acc[0][A][B] = Acc[0][B][A] = 1;
    I = Max[0][A] + B, *I = max(*I, C);
    Max[0][B][A] = *I;
    I = Min[0][A] + B, *I = min(*I, C);
    Min[0][B][A] = *I;
  }
  for (unsigned i(1); i < 30; ++i) {
    unsigned long long *Ptrx, *Ptrn;
    for (unsigned k(1); k <= n; ++k) {
      for (unsigned j(1); j <= n; ++j)
        if (Acc[i - 1][j][k]) {
          for (unsigned J(1); J <= j; ++J)
            if (Acc[i - 1][J][k]) {
              Acc[i][j][J] = Acc[i][J][j] = 1;
              Ptrx = Max[i][j] + J, Ptrn = Min[i][j] + J;
              *Ptrx = max(*Ptrx, Max[i - 1][j][k] + Max[i - 1][k][J]);
              *Ptrn = min(*Ptrn, Min[i - 1][j][k] + Min[i - 1][k][J]);
              Max[i][J][j] = *Ptrx;
              Min[i][J][j] = *Ptrn;
            }
        }
    }
  }
  for (unsigned T(1); T <= t; ++T) {
    A = RD(), B = RD(), C = RD();
    memset(AcT, 0, sizeof(AcT));
    AcT[A] = 1, Tmp[0][A] = Tmp[1][A] = 0;
    for (unsigned i(29), I(0x20000000); C; --i, I >>= 1)
      if (C & I) {
        memcpy(LAcT, AcT, sizeof(AcT));
        memcpy(LastTmp, Tmp, sizeof(Tmp));
        memset(Tmp[0], 0, 840);     // Max
        memset(Tmp[1], 0x3f, 840);  // Min
        for (unsigned k(1); k <= n; ++k)
          if (LAcT[k]) {
            for (unsigned j(1); j <= n; ++j)
              if (Acc[i][j][k]) {
                AcT[j] = 1;
                Tmp[0][j] = max(Tmp[0][j], LastTmp[0][k] + Max[i][k][j]);
                Tmp[1][j] = min(Tmp[1][j], LastTmp[1][k] + Min[i][k][j]);
              }
          }
        C ^= I;
      }
    if (!(Tmp[0][B])) {
      printf("-1 -1\n");
      continue;
    }
    printf("%llu %llu\n", Tmp[1][B], Tmp[0][B]);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
3 3 6
1 2 3
2 3 2
1 3 1
1 1 1
1 3 4
1 3 3
2 3 2
2 3 3
1 2 3
*/