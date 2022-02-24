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
#include <random>
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
unsigned a[105], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  // freopen(".in", "r", stdin);
  freopen("P4184.in", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  std::mt19937 gen(D = time(0));
  printf("%u\n", n = gen() % 20 + 1);
  fprintf(stderr, "%u  Seed %u\n", n, D);
  for (unsigned i(1); i <= n; ++i) {
    if (!Cnt) {
      A = gen() % 15 + 1;
      printf("%u\n", A);
      a[++B] = A, ++Cnt;
      continue;
    }
    else {
      if (gen() & 1) {
        A = gen() % 15 + 1;
        printf("%u\n", A);
        a[++B] = A, ++Cnt;
      }
      else {
        --Cnt;
        while (1) {
          C = (gen() % B) + 1;
          if (a[C]) { printf("%d\n", -a[C]), a[C] = 0; break; }
        }
      }
    }
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}