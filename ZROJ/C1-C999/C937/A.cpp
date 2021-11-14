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
unsigned m, n, Cnt(0), Flg(0), A, B, C, D, t, Ans1(0), Ans2(0), Tmp(0);
char a[2000005];
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = n >> 1;
  if(!(n & 1)) {
    printf("NOT POSSIBLE\n");
    return 0;
  }
  fread(a + 1, 1, 2000002, stdin);
  Flg = 0;
  for (register unsigned i(1); i <= m; ++i) {
    if(a[i] ^ a[i + Flg + m]) {
      if(Flg) {
        Ans1 = 0x3fffffff;
        break;
      }
      if(a[i] == a[i + m + 1]) {
        Ans1 = 1;
        Flg = 1;
      } else {
        Ans1 = 0x3fffffff;
        break;
      }
    }
  }
  Flg = 0;
  for (register unsigned i(1); i <= m; ++i) {
//    printf("%u %u\n", i, Flg);
    if(a[i + Flg] ^ a[i + m + 1]) {
      if(Flg) {
        Ans2 = 0x3fffffff;
        break;
      }
      if(a[i + 1] == a[i + m + 1]) {
        Ans2 = 1;
        Flg = 1;
      } else {
        Ans2 = 0x3fffffff;
        break;
      }
    }
  }
  if((Ans1 > 0x3f3f3f3f) && (Ans2 > 0x3f3f3f3f)) {
    printf("NOT POSSIBLE\n");
    return 0;
  }
  if((Ans1 < 0x3f3f3f3f) && (Ans2 < 0x3f3f3f3f)) {
    for (register unsigned i(1); i <= m; ++i) {
      if(a[i] != a[i + m + 1]) {
        printf("NOT UNIQUE\n");
        return 0;
      }
    }
  }
  if(Ans1 < 0x3f3f3f3f) {
    for (register unsigned i(1); i <= m; ++i) {
      putchar(a[i]);
    }
    putchar('\n');
    return 0;
  }
  for (register unsigned i(m + 2); i <= n; ++i) {
    putchar(a[i]);
  }
  putchar('\n');
//  }
  return Wild_Donkey;
} 
