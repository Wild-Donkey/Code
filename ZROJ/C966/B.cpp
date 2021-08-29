#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
#define Lowbit(x) ((x)&(~((x)-1)))
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
unsigned m, n, Cnt(0), A, B, t, Tmp(0);
long long a[10000005], Tree[10000005], C, Ans(0);
void Add(unsigned x) {
  while (x <= n) {
    Tree[x] += C;
    // printf("Add %u\n", x);
    x += Lowbit(x);
  }
}
void Qry(unsigned x) {
  while (x) {
    Ans += Tree[x];
    x -= Lowbit(x);
  }
}
signed main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  m = RD(), n = RD() + 1;
  for (register unsigned i(1); i < n; ++i) {
    a[i] = RDsg();
  }
  for (register unsigned i(1); i <= m; ++i) {
    register unsigned L(1), R(n - 1), Mid;
    while (L ^ R) {
      // printf("[%u, %u] Mid %u\n", L, R, Mid);
      Mid = ((L + R + 1) >> 1), Ans = a[Mid], Qry(Mid);
      // printf("After Find [%u] %lld\n", Mid, Ans);
      if (Ans > Mid) {
        R = Mid - 1;
      }
      else {
        L = Mid;
      }
    }
    Ans = a[L], Qry(L);
    if (Ans == L) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
    if (i == m) { return 0; }
    A = RD(), B = RD(), C = RDsg();
    Add(A), C = -C, Add(B + 1);
  }
  // 
  return Wild_Donkey;
}
/*
6 10
-10 -8 -6 -4 -2 2 4 6 8 10
9 10 1
7 10 6
5 6 7
1 10 11
1 10 -11
*/