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
bool flg(0);
char inch; 
inline void Clr() {}
struct Node {
  Node *Son[26];
  unsigned Val;
}N[500005], *Cntn(N), *now(N);
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {
      inch = getchar();
    }
    now = N;
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';
      if(!(now->Son[inch])) {
        now->Son[inch] = ++Cntn;
      }
      now = now->Son[inch];
      inch = getchar();
    }
    now->Val = 1;
  }
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {
      inch = getchar();
    }
    now = N;
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';
      if(now->Son[inch]) {
        now = now->Son[inch];
        inch = getchar();
      }
      else {
        flg = 1;
        inch += 'a';
        while (inch >= 'a' && inch <= 'z') {
          inch = getchar();
        }
      }
    }
    if(flg) {
      flg = 0;
      printf("WRONG\n");
      continue;
    }
    if(!(now->Val)) {
      printf("WRONG\n");
      continue;
    }
    if(now->Val >= 2) {
      printf("REPEAT\n");
      continue;
    }
    printf("OK\n"); 
    ++(now->Val);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



