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
unsigned m, n(1), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[10005], b[10005], Flg(0);
unsigned Pre[10005], Pro[10005];
inline void Clr() {
  memset(b, 0, n + 2);
  memset(a, 0, n + 2);
  memset(Pre, 0, (n + 2) << 2);
  memset(Pro, 0, (n + 2) << 2);
  n = 1;
  Flg = 0;
}
int main() {
//  freopen("HDU3183.in", "r", stdin);
//  freopen("HDU3183.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
  while (scanf("%s", a + 1) != -1) { 
    m = RD();
    while (a[n]) {
      ++n;
    }
//    printf("n = %u\n", n); 
    for (register unsigned i(0); i <= n; ++i) {
      Pre[i] = i - 1;
      Pro[i] = i + 1;
//      printf("%u %u %u\n", i, Pre[i], Pro[i]);
    }
    for (register unsigned i(1), j(0); i <= m; ++i) {
      while (a[j] <= a[Pro[j]]) {
        j = Pro[j];
      }
//      printf("%u %u %u\n", j, Pre[j], Pro[j]);
      b[j] = 1;
      Pro[Pre[j]] = Pro[j];
      Pre[Pro[j]] = Pre[j];
      j = Pre[j];
//      printf("%u %u %u\n", j, Pre[j], Pro[j]);
    }
    for (register unsigned i(1); i < n; i = Pro[i]){
      if(!b[i]) {
        if (a[i] == '0') {
          if(!Flg){
            continue;
          } else {
            printf("%c", a[i]);
          }
        } else {
          printf("%c", a[i]);
          Flg = 1;
        }
      }
    }
//    printf("%u\n", Flg);
    if(!Flg) putchar('0');
    putchar('\n'); 
    Clr();
  }
//  }
  return Wild_Donkey;
}

