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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, N, Cnt(0), A, B, C, D, t, List[90], Nu[90];
unsigned long long f[10][105][95], Ans(0);
bool b[10005];
char s[10005];
inline void Clr() {}
inline bool Jud(unsigned x) {
  unsigned tmp(0x3f);
  while (x) {
    if (x & 1) {
      if (tmp) {
        tmp = 0;
      } else {
        return Wild_Donkey;
      }
    } else {
      ++tmp;
    }
    x >>= 1;
  }
  return 1;
}
inline unsigned Getnum(unsigned x) {
  unsigned tmp(0);
  while (x) {
    if (x & 1) {
      ++tmp;
    }
    x >>= 1;
  }
  return tmp;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  N = (1 << n) - 1;
  memset(List, 0, sizeof(List));
  memset(f, 0, sizeof(f));
  for (register unsigned i(0); i <= N; ++i) {
    if (Jud(i)) {
      List[++List[0]] = i;
      Nu[List[0]] = Getnum(i);
//      printf("%u %x %u\n", List[0], i, Nu[List[0]]);
    }
  }
  f[0][1][0] = 1;
  for (register unsigned i(1); i <= n; ++i) {            // line (9)
    for (register unsigned j(1); j <= List[0]; ++j) {    // this line (89)
      for (register unsigned k(1); k <= List[0]; ++k) {  // last line (89)   
        if (!(List[j] & List[k] || (List[j] >> 1) & List[k] || (List[j] << 1) & List[k])) {   // No war
          for (register unsigned i_(Nu[j]); i_ <= m; ++i_) {    // num of kings (81)
            f[i][j][i_] += f[i - 1][k][i_ - Nu[j]];
//            printf("f[%u][%u][%u] %u %u  ", i, j, i_, f[i][j][i_], k);
          }
        }
//        putchar('\n');
      }
    }
  }
  for (register unsigned i(1); i <= List[0]; ++i) {
    Ans += f[n][i][m];
  }
  printf("%llu\n", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
9 15
31122500764
*/
