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
unsigned long long f[500005], Sum[500005], L, R, C;
unsigned long long LAns, RAns, Ans;
unsigned Stack[500005][3], STop(0);
unsigned a[500005], g[500005], m, n;
unsigned A, B, D, t, LPos, RPos, Pos;
unsigned Cnt(0), Tmp(0);
inline unsigned long long Trans(unsigned x, unsigned y) { return f[y] + Sum[y] + Sum[x] + C - Sum[(x + y) >> 1] - Sum[(x + y + 1) >> 1]; }
inline long long Calc() {
  STop = 0, Stack[++STop][0] = 1, Stack[STop][1] = n, Stack[STop][2] = 0;
  for (unsigned i(1), j(1); i <= n; ++i) {
    while (Stack[j][1] < i) ++j;
    f[i] = Trans(i, Stack[j][2]);
    g[i] = g[Stack[j][2]] + 1;
    // printf("%u -> %u Ans %llu Num %u Rel %llu\n", Stack[j][2], i, f[i], g[i], f[i] - g[i] * C);
    while ((STop > j) && (Trans(Stack[STop][0], Stack[STop][2]) >= Trans(Stack[STop][0], i))) --STop;
    unsigned BL(Stack[STop][0]), BR(Stack[STop][1] + 1), BMid, Bef(Stack[STop][2]);
    while (BL ^ BR) {
      BMid = ((BL + BR) >> 1);
      if (Trans(BMid, Bef) < Trans(BMid, i)) BL = BMid + 1;
      else BR = BMid;
    }
    Stack[STop][1] = BL - 1;
    if (BL <= n) Stack[++STop][0] = BL, Stack[STop][1] = n, Stack[STop][2] = i;
  }
  return f[n] - g[n] * C;
}
signed main() {
  // freopen("P6246_1.in", "r", stdin);
  // freopen("P6246.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  sort(a + 1, a + n + 1);
  for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + a[i];
  L = 0, C = R = Sum[n], LPos = 1, RPos = n, LAns = Calc(), RAns = 0;
  while (L <= R) {
    C = ((L + R) >> 1);
    Ans = Calc(), Pos = g[n];
    if (Pos == m) { printf("%llu\n", Ans)/*, system("pause")*/;return 0; }
    // printf("[%llu %llu] %llu Ans %llu Pos %u\n", L, R, C, Ans, Pos);
    if (Pos < m) R = C - 1, LPos = Pos, LAns = Ans;
    else L = C + 1, RPos = Pos, RAns = Ans;
  }
  printf("%llu\n", LAns - (LAns - RAns) / (RPos - LPos) * (m - LPos));
  //  }
  // system("pause");
  return Wild_Donkey;
}