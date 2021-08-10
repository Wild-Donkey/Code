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
unsigned a[10005], m, n, Cnt(0), t, Ans(0), Tmp(0);
char b[10005], A[100005];
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  for (register unsigned i(1); i <= 4; ++i) {
    memset(A, 0, sizeof(A));
    scanf("%s", A);
    if(A[0] ^ 'H') {
      if(A[0] == '2') {
        if(A[1] == 'B') {
          ++b[2];
          continue;
        }
      }
      if(A[0] == '3') {
        if(A[1] == 'B') {
          ++b[3];
          continue;
        }
      }
    } else {
      if(!A[1]) {
        ++b[1];
        continue;
      }
      if(A[1] == 'R') {
        ++b[4];
        continue;
      }
    }
  }
  for (register unsigned i(1); i <= 4; ++i) {
    if(!b[i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
//  }
  return Wild_Donkey;
}

