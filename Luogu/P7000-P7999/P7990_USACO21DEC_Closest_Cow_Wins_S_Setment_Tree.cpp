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
pair<unsigned, unsigned> Grass[200005];
unsigned Rg[200005][2], Cow[200005], b[400005];
unsigned Stack[200005], STop(0);
unsigned long long Ans(0);
unsigned m, n, My;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  set<unsigned> List;
  Node* LS, *RS;
  unsigned long long Mx, Tag;
  unsigned MxP;
}N[800005], *CntN(N);
inline void Build(Node*x, unsigned L, unsigned R) {
//  printf("Build %u [%u, %u]\n", x - N, L, R);
  x->MxP = L;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
inline void Chg(Node* x, unsigned L, unsigned R) {
//  printf("Chg %u [%u, %u] for [%u, %u]\n", x - N, L, R, A, B);
  if((A <= L) && (R <= B)) {
    x->List.insert(C), x->Tag += Grass[C].second, x->Mx += Grass[C].second;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Chg(x->LS, L, Mid);
  if(B > Mid) Chg(x->RS, Mid + 1, R);
  if(x->LS->Mx >= x->RS->Mx) x->Mx = x->Tag + x->LS->Mx, x->MxP = x->LS->MxP;
  else x->Mx = x->Tag + x->RS->Mx, x->MxP = x->RS->MxP;
}
inline void Access(Node* x, unsigned L, unsigned R) {
//  printf("Access %u (%u) [%u, %u] LS %u RS %u\n", x - N, A, L, R, x->LS - N, x->RS - N);
  for (auto i:x->List) Stack[++STop] = i;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Access(x->LS, L, Mid);
  else Access(x->RS, Mid + 1, R);
}
inline void Ers(Node* x, unsigned L, unsigned R) {
//  printf("Ers %u [%u, %u] for [%u, %u]\n", x - N, L, R, A, B);
  if((A <= L) && (R <= B)) {
//    printf("Erase %u\n", C);
    x->List.erase(C);
//    for (auto i:x->List) printf("%u ", i); putchar(0x0A);
    x->Tag -= Grass[C].second, x->Mx -= Grass[C].second;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Ers(x->LS, L, Mid);
  if(B > Mid) Ers(x->RS, Mid + 1, R);
  if(x->LS->Mx >= x->RS->Mx) x->Mx = x->Tag + x->LS->Mx, x->MxP = x->LS->MxP;
  else x->Mx = x->Tag + x->RS->Mx, x->MxP = x->RS->MxP;
}
//  inline void Clr() {}
signed main() {
  freopen("9.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), My = RD();
  for (unsigned i(1); i <= n; ++i) Grass[i].first = RD() + 1, Grass[i].second = RD();
  for (unsigned i(1); i <= m; ++i) Cow[i] = RD() + 1;
  sort(Grass + 1, Grass + n + 1), sort(Cow + 1, Cow + m + 1);
  Cow[0] = 0, Cow[++m] = 1000000002;
  for (unsigned i(0), j(1); j <= n; ++j) {
    while(Cow[i + 1] < Grass[j].first) ++i;
    unsigned Dis;
    if((i ^ (m - 1)) && ((!i) || (Cow[i + 1] - Grass[j].first < Grass[j].first - Cow[i]))) {
      Rg[j][1] = Cow[i + 1]; 
      Dis = Cow[i + 1] - Grass[j].first;
      Rg[j][0] = (Dis <= Grass[j].first) ? (Grass[j].first - Dis + 1) : 1;
    }
    else {
      Rg[j][0] = Cow[i] + 1;
      Dis = Grass[j].first - Cow[i];
      Rg[j][1] = Grass[j].first + Dis;
    }
  }
  for (unsigned i(1); i <= n; ++i) b[++Cnt] = Rg[i][0], b[++Cnt] = Rg[i][1];
  sort(b + 1, b + Cnt + 1), Cnt = unique(b + 1, b + Cnt + 1) - b;
  printf("Cnt %u\n", Cnt);
  Build(N, 1, Cnt - 1);
  for (unsigned i(1); i <= n; ++i) {
    A = Rg[i][0] = lower_bound(b + 1, b + Cnt, Rg[i][0]) - b;
    B = Rg[i][1] = lower_bound(b + 1, b + Cnt, Rg[i][1]) - b;
    C = i, Chg(N, 1, Cnt - 1);
  }
//  for (auto i:Test) printf("%u ", i); putchar(0x0A);
  while (My && N->Mx) {
    Ans += N->Mx, ++D;
    A = N->MxP, Access(N, 1, Cnt - 1);
//    sort(Stack + 1, Stack + STop + 1), STop = unique(Stack + 1, Stack + STop + 1) - Stack - 1;
//    printf("This Time %llu (%u) Size %u\n", N->Mx, N->MxP, STop);
//    for (unsigned i(1); i <= STop; ++i) printf("%u ", Stack[i]); putchar(0x0A);
//    system("pause");
    for (unsigned i(1); i <= STop; ++i)
      C = Stack[i], A = Rg[C][0], B = Rg[C][1], Ers(N, 1, Cnt - 1);
    --My, STop = 0;
  }
  printf("%llu %u\n", Ans, D);
//  }
//  system("pause");
  return Wild_Donkey;
}
/*
This Time 5300752662 (130410) Size 70306
This Time 5097205812 (194919) Size 32120
This Time 4819560503 (227404) Size 16203
This Time 4497713821 (243495) Size 7971
This Time 3825465872 (247157) Size 1801
This Time 3481042456 (249741) Size 1272
This Time 2439469646 (249993) Size 137
*/
