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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char s[105], Flg;
inline void Clr() {
  n = RD(), m = RD(), Flg = 0, Ans = 0;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      scanf("%s", s + 1);
      if(Flg) continue; 
      for (register unsigned j(1); j <= m; ++j) {
        if(s[j] == 'R') {
          if(!Ans) {
            Ans = ((j + i) % 2) + 1;
          } else {
            if(Ans ^ (((j + i) % 2) + 1)) {
              Flg = 1; 
            }
          }
        }
        if(s[j] == 'W') {
          if(!Ans) {
            Ans = ((j + i + 1) % 2) + 1;
          } else {
            if(Ans ^ (((j + i + 1) % 2) + 1)) {
              Flg = 1;
            }
          }
        }
      }
    }
    if(Flg) {
      printf("NO\n"); continue;
    }
    if(!Ans) {
      Ans = 1;
    }
    Ans -= 1;
    printf("YES\n");
    for (register unsigned i(1); i <= n; ++i) {
      for (register unsigned j(1); j <= m; ++j) {
        putchar((Ans ^ ((i + j) % 2)) ? 'W' : 'R');
      }
      putchar('\n');
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



