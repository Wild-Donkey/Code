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
inline long long RD() {
  long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline long long RDsg() {
  long long rdtp(0), rdsg(1);
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
long long a[100005], b[100005], A, B, C, D, Ans(0);
unsigned m, n, q, Tmp(0), Dest(0);
unsigned Judge (unsigned x) {
  if(a[x] + C < b[Dest - x + 1] + D) {
    return 1;
  }
  return 0;
}
int main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), q = RD();
  Dest = ((m + n + 1) >> 1);
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD() - a[1];
  }
  a[0] = -1000000000000000, A = a[1] + 1000000000000000, a[1] = 0, a[n + 1] = 0x3f3f3f3f3f3f3f3f;
  for (register unsigned i(1); i <= m; ++i) {
    b[i] = RD() - b[1];
  }
  b[0] = -1000000000000000, B = b[1] + 1000000000000000, b[1] = 0, b[m + 1] = 0x3f3f3f3f3f3f3f3f;
  for (register unsigned i(1); i <= q; ++i) {
    if(RD() & 1) {
      C = A + RDsg();
      D = B;
    } else {
      D = B + RDsg();
      C = A; 
    }
    register unsigned L((Dest >= m) ? (Dest - m) : 0), R(min(n, Dest)), Mid;
    while (L ^ R) {
//      printf("[%u %u]\n", L, R);
      Mid = ((L + R + 1) >> 1);
      if(Judge(Mid)) {
        L = Mid;
      } else {
        R = Mid - 1;
      }
    }
//    printf("L: %u Dest - L: %u\n", L, Dest - L);
    Ans = max(a[L] + C, b[Dest - L] + D);
    if (!((n + m) & 1)) {
      Ans += min(a[L + 1] + C, b[Dest - L + 1] + D); 
      if(Ans & 1) {
        printf("%lld.5\n", (Ans >> 1) - 1000000000000000);
      } else {
        printf("%lld\n", (Ans >> 1) - 1000000000000000);
      }
      continue;
    }
    printf("%lld\n", Ans - 1000000000000000);
  }
//  }
  return Wild_Donkey;
}

