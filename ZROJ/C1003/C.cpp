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
#include <string>
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
unsigned f, g[505], a[1005], m, n;
unsigned B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned To[505][2];
char Flg(0);
inline void Clr() {
  memset(a, 0, sizeof(a));
  n = RD(), Flg = Cnt = 0, Ans = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  for (;;){
    Clr();
    if(!n) return 0;
    for (unsigned i(1); i <= n; ++i) {
      To[i][0] = RD();
      To[i][1] = RD();
    }
    a[C = 1] = ++Cnt;
    for (;;) {
      if(a[To[C][0]]) {
        if(a[To[C][1]]) break;
        else {
          C = To[C][1];
          a[C] = ++Cnt;
        }
      } else {
        C = To[C][0];
        a[C] = ++Cnt;
      }
    }
    for (unsigned i((n << 1) - 1); i > n; --i) a[i] = a[i - n];
    for (unsigned i(1); i <= n; ++i) if(!a[i]) {Flg = 1; break;}
    if(Flg) {
      printf("Not solvable.\n");
      continue;
    }
    for (unsigned i(1); i <= n; ++i) {
      unsigned *A(a + i - 1);
      memset(g, 0x3f, sizeof(g)), g[0] = 0;
      for (unsigned j(1); j <= n; ++j) {
//        for (unsigned k(0); k <= n + 1; ++k) printf("%u ", g[k]);
//        putchar(0x0A);
        unsigned Lb(lower_bound(g, g + n + 2, A[j]) - g - 1);
//        printf("Lb %u\n", Lb);
        f = Lb + 1;
        g[f] = min(A[j], g[f]);
        Ans = max(Ans, f);
//        printf("f[%u] = %u\n", j, f);
      }
    }
    for (unsigned i(1); i <= n; ++i) {
      unsigned *A(a + i - 1);
      memset(g, 0x3f, sizeof(g)), g[0] = 0;
      for (unsigned j(n); j; --j) {
        unsigned Lb(lower_bound(g, g + n + 2, A[j]) - g - 1);
        f = Lb + 1;
        g[Lb + 1] = min(A[j], g[Lb + 1]);
        Ans = max(Ans, f);
//        printf("g[%u] = %u\n", j, f);
      }
    }
    printf("Knot solvable.\n%u\n", n - Ans);
  }
  return Wild_Donkey;
}
/*
6
5 2
1 4
4 6
2 3
1 6
3 5
*/

