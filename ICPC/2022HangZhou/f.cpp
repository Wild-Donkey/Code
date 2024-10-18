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
const unsigned long long Base[3] = {29, 37, 998244353};
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
set<unsigned long long> Buck[3];
char Find(char *x) {
  unsigned Len(strlen(x));
  unsigned long long Hs[3];
  Hs[0] = Hs[1] = Hs[2] = 0;
  for (unsigned i(0); i < Len; ++i) {
    Hs[0] = Hs[0] * Base[0] + x[i], Hs[1] = Hs[1] * Base[1] + x[i],
    Hs[2] = Hs[2] * Base[2] + x[i];
  }
  if (Buck[0].count(Hs[0])) return 1;
  if (Buck[1].count(Hs[1])) return 1;
  if (Buck[2].count(Hs[2])) return 1;
  Buck[0].insert(Hs[0]);
  Buck[1].insert(Hs[1]);
  Buck[2].insert(Hs[2]);
  printf("%s\n", x);
  return 0;
}
//  inline void Clr() {}
char Itmp[10005];
const char Bie[4] = "bie";
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    n = RD();
    char FLG = 0;
    for (unsigned i(1); i <= n; ++i) {
      scanf("%s", Itmp);
      m = strlen(Itmp);
      char Flg = 0;
      for (unsigned j(0), k(0); j < m;) {
        if (Bie[k] == Itmp[j]) {
          ++k, ++j;
          if (k == 3) {
            Flg = 1;
            break;
          }
        } else {
          if (k)
            k = 0;
          else
            ++j;
        }
      }
      if (Flg) {
        if (!Find(Itmp)) FLG = 1;
      }
    }
    if (!FLG) printf("Time to play Genshin Impact, Teacher Rice!\n");
  }
  //  system("pause");
  return Wild_Donkey;
}