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
unsigned a[15], List[1050], m, n, N(0), Cnt(0), A, B, C, D, t;
unsigned long long f[15][15][1050], Ans(0);
char b[15];
inline unsigned Count(unsigned x) {
  register unsigned Tmp(0);
  while (x) {
    Tmp += (x & 1);
    x >>= 1;
  }
  return Tmp;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), N = 1 << n;
  for (register unsigned i(1); i <= n; ++i) {
    scanf("%s", b + 1);
    for (register unsigned j(1); j <= n; ++j) {
      a[i] <<= 1;
      a[i] += (b[j] == '.') ? (0) : (1);
      printf("%u\n", j);
    }
    printf("A[%u] = %u\n", i, a[i]);
  }
  f[0][0][N - 1] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    f[i][0][N - 1] = 1;
    for (register unsigned k(1); k < N; ++k) {
      for (register unsigned j(Count(k)); j <= m; ++j) {
//        printf("Faq %u\n", i);
        if(!(k & a[i])) {
          for (register unsigned l(1); l < N; ++l) {
            if(k & l) {
              f[i][j][k] += f[i - 1][j - Count(k)][l];
            }
//            printf("%u %u %u %u\n", i, k, j, l);
          }
        }
      }
      printf("%u\n", f[i][m][k]);
      Ans += f[i][m][k];
    }
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

