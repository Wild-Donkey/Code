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
unsigned m, n, Cnt(0), A, B, C, D, t, CntNo(0);
char b[1005], a[1005];
inline void Clr() {
  n = RD();
  CntNo = Cnt = 0;
  scanf("%s", b + 1);
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    if(n == 1) {
      printf("BOB\n");
      continue;
    }
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = b[i] - '0';
      if(!a[i]) {
        ++Cnt;
      }
    }
    for (register unsigned i(1); (i << 1) <= n; ++i) {
      if(a[i] ^ a[n - i + 1]) {
        ++CntNo;
      }
    }
    if(n & 1) {
      if (a[(n >> 1) + 1]) {
        if(CntNo) {
          printf("ALICE\n");
        }
        else {
          printf("BOB\n");
        }
      }
      else {
        if(Cnt <= 1) {
          printf("BOB\n");
          continue;
        }
        printf("ALICE\n");
      }
    }
    else {
      if(CntNo)
      printf("BOB\n");
    }
    
//    for (register unsigned i(1); (i << 1) <= n; ++i) {
//      if(a[i] ^ a[n - i + 1]) {
//        ++Cnt;
//      }
//    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}

