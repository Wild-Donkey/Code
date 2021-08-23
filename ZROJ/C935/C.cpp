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
//  printf("#1 %u == %u\n", x, x + upper_bound(b + 1, b + m + 1, a[x] + C - D) - 1 - b);
  return x + upper_bound(b + 1, b + m + 1, a[x] + C - D) - 1 - b < Dest;
}
unsigned Judge2 (unsigned x) {
//  printf("#2 %u == %u\n", x, x + upper_bound(a + 1, a + n + 1, b[x] + D - C) - 1 - a);
  return x + upper_bound(a + 1, a + n + 1, b[x] + D - C) - 1 - a < Dest;
}
int main() {
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
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
//  for (register unsigned i(1); i <= n; ++i) {
//    printf("a[%u] = %lld %lld\n", i, a[i], a[i] + A - B);
//  }
//  for (register unsigned i(1); i <= m; ++i) {
//    printf("b[%u] = %lld %lld\n", i, b[i], b[i] + B - A);
//  }
  for (register unsigned i(1); i <= q; ++i) {
    if(RD() & 1) {
      C = A + RDsg();
      D = B;
    } else {
      D = B + RDsg();
      C = A; 
    }
    register unsigned L(0), R(n), Mid;
    while (L ^ R) {
//      printf("#1 [%u, %u]\n", L, R);
      Mid = ((L + R + 1) >> 1);
      if(Judge(Mid)) {
        L = Mid;
      } else {
        R = Mid - 1;
      }
    }
    Tmp = L;
//    printf("Done %u\n", Tmp);
    L = upper_bound(b + 1, b + m + 1, a[Tmp] + C - D) - 1 - b, R = upper_bound(b + 1, b + m + 1, a[Tmp + 1] + C - D) - 1 - b;
    while (L ^ R) {
//      printf("#2 [%u, %u]\n", L, R);
      Mid = ((L + R + 1) >> 1);
      if(Judge2(Mid)) {
        L = Mid;
      } else {
        R = Mid - 1;
      }
    }
//    Tmp = Dest - L + 1; 
    while (Tmp + L >= Dest) {
//      printf("%u %u\n", Tmp, L);
      if(a[Tmp - 1] + C > b[L - 1] + D) {
        --Tmp;
      } else {
        --L;
      }
    }
    while (Tmp + L + 1 < Dest) {
//      printf("%u %u\n", Tmp, L);
      if(a[Tmp + 1] + C < b[L + 1] + D) {
        ++Tmp;
      } else {
        ++L;
      }
    }
//    printf("%u %u\n", Tmp, L);

    Ans = min(a[Tmp + 1] + C, b[L + 1] + D);
    if (!((n + m) & 1)) {
      if(a[Tmp + 1] + C < b[L + 1] + D) {
        Ans += min(a[Tmp + 2] + C, b[L + 1] + D); 
      } else {
        Ans += min(a[Tmp + 1] + C, b[L + 2] + D);
      }
//      printf("Cao %lld\n", Ans - 2000000000000000);
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

