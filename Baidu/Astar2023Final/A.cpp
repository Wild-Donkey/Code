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
char Map[3005][3005], OK[3005];
unsigned A, B, C, D, t;
unsigned VerU, VerD, HorL, HorR;
unsigned Cnt(0), Tmp(0);
char Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s\n", Map[i] + 1);
    for (unsigned j(1); j <= m; ++j)
      if (Map[i][j] == 'S') A = i, B = j;
  }
  for (VerU = A; VerU && Map[VerU][B] != '#';) --VerU;
  ++VerU;
  for (VerD = A; VerD <= n && Map[VerD][B] != '#';) ++VerD;
  --VerD;
  for (HorL = B; HorL && Map[A][HorL] != '#';) --HorL;
  ++HorL;
  for (HorR = B; HorR <= m && Map[A][HorR] != '#';) ++HorR;
  --HorR;
  // printf("[%u, %u][%u, %u]\n", VerU, VerD, HorL, HorR);
  if (VerU < VerD) {
    memset(OK, 1, n + 1);
    unsigned Last(0);
    for (unsigned i(B + 1); i <= m; ++i) {
      Last = 0;
      for (unsigned j(VerU); j <= VerD; ++j) {
        if (Map[j][i] == '#') {
          OK[j] = 0, Last = 0;
          continue;
        }
        if (!OK[j]) continue;
        if (Last == 0) Last = j;
        if (Last && Last <= A && j >= A && Last < j) {
          printf("Yes\n");
          return 0;
        }
      }
    }
    memset(OK, 1, n + 1);
    for (unsigned i(B - 1); i; --i) {
      Last = 0;
      for (unsigned j(VerU); j <= VerD; ++j) {
        if (Map[j][i] == '#') {
          OK[j] = 0, Last = 0;
          continue;
        }
        if (!OK[j]) continue;
        if (Last == 0) Last = j;
        if (Last && Last <= A && j >= A && Last < j) {
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  if (HorL < HorR) {
    memset(OK, 1, m + 1);
    unsigned Last(0);
    for (unsigned i(A + 1); i <= n; ++i) {
      Last = 0;
      for (unsigned j(HorL); j <= HorR; ++j) {
        if (Map[i][j] == '#') {
          OK[j] = 0, Last = 0;
          continue;
        }
        if (!OK[j]) continue;
        if (Last == 0) Last = j;
        if (Last && Last <= B && j >= B && Last < j) {
          printf("Yes\n");
          return 0;
        }
      }
    }
    memset(OK, 1, m + 1);
    for (unsigned i(A - 1); i; --i) {
      Last = 0;
      for (unsigned j(HorL); j <= HorR; ++j) {
        if (Map[i][j] == '#') {
          OK[j] = 0, Last = 0;
          continue;
        }
        if (!OK[j]) continue;
        if (Last == 0) Last = j;
        if (Last && Last <= B && j >= B && Last < j) {
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}