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
#include <random>
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
unsigned long long Mod(1000000007);
unsigned a[300005], m, n, Ans(0);
unsigned A, B, C, D, t, Opt, OV;
unsigned Cnt(0), Tmp(0);
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
//  inline void Clr() {}
signed main() {
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) {
    // printf("Solve %u\n", i);
    Opt = RD(), A = RD(), B = RD();
    if (Opt < 4 || Opt > 5) {
      switch (Opt) {
      case(1): {
        for (unsigned j(A); j <= B; ++j) Ans += a[j], Mn(Ans);
        printf("%u\n", Ans);
        break;
      }
      case(2): {
        OV = RD();
        for (unsigned j(A); j <= B; ++j) a[j] = OV;
        break;
      }
      case(3): {
        OV = RD();
        for (unsigned j(A); j <= B; ++j) a[j] += OV, Mn(a[j]);
        break;
      }
      case(6): {
        unsigned Mid((B - A) >> 1);
        for (unsigned j(0); j <= Mid; ++j) swap(a[A + j], a[B - j]);
        break;
      }
      }
    }
    else {
      C = RD(), D = RD();
      unsigned Len = D - C + 1;
      if (Opt & 1) for (unsigned j(0); j < Len; ++j) swap(a[A + j], a[C + j]);
      else for (unsigned j(0); j < Len; ++j) a[C + j] = a[A + j];
    }
  }
  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]); putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
10 10
911616723 667663273 691146885 965015377 205230478 641859055 232410115 817771875 323420518 700453455
2 4 4 266128540
4 9 10 1 2
6 5 8
4 5 7 8 10
3 7 9 703466373
4 6 8 3 5
1 7 10
3 1 10 390058271
2 2 9 873260451
3 6 7 449097252
*/