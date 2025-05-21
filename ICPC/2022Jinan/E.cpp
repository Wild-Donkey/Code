#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(), m = RD(); }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    A = n / m;
    B = n % m;
    n /= 2;
    if (!A) {
      printf("Yes\n");
      continue;
    }
    C = n / A;
    D = n % A;
    C = C - D;
    // printf("C %u D %u\n", C, D);
    if (m - B < C) {
      Tmp = C - m + B;
      Tmp = (Tmp + A) / (A + 1);
      D += Tmp * A;
      C -= Tmp * (A + 1);
      if (D <= B && C <= 0x3f3f3f3f)
        printf("Yes\n");
      else
        printf("No\n");
      continue;
    }
    if (D <= B)
      printf("Yes\n");
    else {
      Tmp = D - B;
      Tmp = (Tmp + A - 1) / A;
      C += Tmp * (A + 1);
      D -= Tmp * A;
      if (C <= m - B && D <= 0x3f3f3f3f)
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2
7 3
13 5
*/