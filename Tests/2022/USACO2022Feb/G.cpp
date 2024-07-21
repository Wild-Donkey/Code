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
unsigned long long h[263005][18], g[263005], f[263005];
unsigned Ed[18], m, n, N;
char IO[20];
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  N = (1 << (n = RD()));
  for (unsigned i(0); i < n; ++i) {
    char Flg(1);
    for (unsigned j(0); j < n; ++j) {
      Tmp = RD() - 1;
      if (Flg) Ed[i] |= (1 << Tmp);
      if (Tmp == i) Flg = 0;
    }
  }
  for (unsigned i(0); i < n; ++i) h[1 << i][i] = 1;
  h[0][0] = 1;
  for (unsigned i(1); i < N; ++i) {
    unsigned Low(0);
    while ((1 << Low) <= (i >> 1)) ++Low;
    for (unsigned End(0); End <= Low; ++End)
      if (((i >> End) & 1)) {
        if ((Ed[End] >> Low) & 1) g[i] += h[i][End];
        // printf("i %u End %u\n", i, End);
        for (unsigned To(0); To < Low; ++To)
          if ((!((i >> To) & 1)) && ((Ed[End] >> To) & 1)) {
            h[i | (1 << To)][To] += h[i][End];
          }
      }
  }
  f[0] = g[0] = 1;
  for (unsigned i(0); i < N; ++i) {
    unsigned Low(0);
    while ((1 << Low) <= (i >> 1)) ++Low;
    for (unsigned j(i); j >> Low; j = (j - 1) & i) f[i] += f[i ^ j] * g[j];
  }
  m = RD(), --N;
  for (unsigned i(1); i <= m; ++i) {
    scanf("%s", IO), Cnt = 0;
    for (unsigned j(0); j < n; ++j)
      if (IO[j] == 'G') Cnt |= (1 << j);
    printf("%llu\n", f[Cnt] * f[N ^ Cnt]);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4
3 2 4 1
3 1 4 2
2 1 4 3
2 1 3 4
5
HHHH
HHGG
GHGH
HGGG
GHHG
*/