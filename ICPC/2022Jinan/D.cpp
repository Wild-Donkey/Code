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
unsigned m, n, Stil;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Mn, Mx;
inline void Clr() {
  Stil = A = RD(), C = B = RD();
  m = 0;
}
struct Prob {
  char Type;
  unsigned Arg1, Arg2;
} P[15];
struct Fro {
  unsigned Num, Bef, Af;
  char Chos;
} F[15];
unsigned Must, Use, Ned;
char DFS(unsigned Dep, unsigned Cur) {
  if (Dep == Stil + 1) { return Must <= Mx && Must + Use >= Mn; }
  if (m - Cur > Stil - Dep) {
    if (DFS(Dep, Cur + 1)) return 1;
  }
  F[Cur].Chos = 1;
  Must += F[Cur].Bef, Use += F[Cur].Af - 1;
  if (DFS(Dep + 1, Cur + 1)) return 1;
  F[Cur].Chos = 0;
  Must -= F[Cur].Bef, Use -= F[Cur].Af - 1;
  return 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD(), n = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      char CrTm(getchar());
      while (CrTm != '+' && CrTm != '?' && CrTm != '-' && CrTm != '.')
        CrTm = getchar();
      P[i].Type = CrTm;
      if (P[i].Type == '.') continue;
      if (P[i].Type == '-') {
        P[i].Arg1 = RD();
        continue;
      }
      P[i].Arg1 = RD(), P[i].Arg2 = RD();
      if (P[i].Type == '+') {
        --Stil;
        C -= (P[i].Arg1 - 1) * 20 + P[i].Arg2;
        continue;
      }
      F[++m] = {i, P[i].Arg2 - P[i].Arg1, P[i].Arg1, 0};
    }
    C -= Stil * 240;  // (C - 20k) should in [0, 59 * Stil]
    if (C >= 0x3f3f3f3f || Stil >= 0x3f3f3f3f) {
      printf("No\n");
      continue;
    }
    Mx = C / 20;
    D = max(C, 59 * Stil) - 59 * Stil;
    Mn = (D + 19) / 20;
    Must = 0, Use = 0;
    if (!DFS(1, 1)) {
      printf("No\n");
      continue;
    }
    Ned = max(Must, Mn), C -= Ned * 20;
    for (unsigned i(1); i <= m; ++i)
      if (F[i].Chos) Ned -= F[i].Bef;
    m = 0;
    printf("Yes\n");
    for (unsigned i(1); i <= n; ++i) {
      if (P[i].Type == '.') {
        printf(".\n");
        continue;
      }
      if (P[i].Type == '-') {
        printf("- %u\n", P[i].Arg1);
        continue;
      }
      if (P[i].Type == '+') {
        printf("+ %u/%u\n", P[i].Arg1, P[i].Arg2);
        continue;
      }
      ++m;
      if (F[m].Chos) {
        Tmp = min(C, (unsigned)59), C -= Tmp;
        Cnt = min(Ned, F[m].Af - 1), Ned -= Cnt;
        printf("+ %u/%u\n", F[m].Bef + Cnt + 1, Tmp + 240);
      } else
        printf("- %u\n", F[m].Bef + F[m].Af);
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1 13
7 951
+ 1/6
? 3 4
+ 4/183
- 2
+ 3/217
.
.
.
+ 2/29
+ 1/91
.
+ 1/22
.




6 2
1 100
.
? 3 4
2 100
+ 1/1
+ 1/2
0 0
- 5
- 6
2 480
? 100 100
? 100 100
2 480
? 99 100
? 100 100
1 2000
? 100 100
? 100 100

*/