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
long long Ans(0); 
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0),  Tmp(0);
struct Rag {
  unsigned L, R, Val;
  inline const char operator < (const Rag& x) const {return Val > x.Val;}
}Ra[300005];
struct Node {
  Node* LS, * RS;
  long long Val, Tag;
  int Lay, LTag, RgL, RgR;
  inline void PsDw() {
    if(LTag) {
      LS->LTag += LTag;
      RS->LTag += LTag;
      LS->Lay += LTag;
      RS->Lay += LTag;
      LS->Tag += Tag;
      RS->Tag += Tag;
      LS->Val += Tag;
      RS->Val += Tag;
      LTag = Tag = 0;
    }
  }
  inline void PsUp () {
    Lay = max(LS->Lay, RS->Lay);
    Val = max(LS->Val, RS->Val);
    if(LS->Lay == RS->Lay) {
      if(LS->RgR + 1 == RS->RgL) RgL = LS->RgL, RgR = RS->RgR;
      else RgL = LS->RgL, RgR = LS->RgR;
      return;
    }
    if(LS->Lay > RS->Lay) RgL = LS->RgL, RgR = LS->RgR;
    else RgL = RS->RgL, RgR = RS->RgR;
  } 
  inline void Chg(unsigned L, unsigned R) {
//    printf("Chg [%u, %u]\n", L, R);
    if((A <= L) && (R <= B)) {
      ++LTag, ++Lay, Val += C, Tag += C;
      return;
    }
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Chg(L, Mid);
    if(B > Mid) RS->Chg(Mid + 1, R);
    PsUp();
  }
  inline void Dec(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {LTag -= Lay, Tag -= Val, Lay = Val = 0; return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Dec(L, Mid);
    if(B > Mid) RS->Dec(Mid + 1, R);
    PsUp();
  }
}N[600005], * CntN(N);
inline void Clr() {
  CntN = N, Ans = 0;
  D = RD(), n = RD(), m = RD();
}
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Lay = x->Val = x->Tag = x->LTag = 0;
  x->RgL = L, x->RgR = R;
  if(L == R) {
    x->LS = x->RS = NULL;
    return;
  }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
signed main() {
//    freopen("A6.in", "r", stdin);
//    freopen("A.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) Ra[i].Val = RD(), Ra[i].L = RD(), Ra[i].R = RD();
    sort(Ra + 1, Ra + n + 1), Build(N, 1, D);
//    for (unsigned i(1); i <= n; ++i) 
    for (unsigned i(1); i <= n; ++i) {
//      printf("[%u, %u] %u\n", Ra[i].L, Ra[i].R, Ra[i].Val);
      A = Ra[i].L, B = Ra[i].R, C = Ra[i].Val, N->Chg(1, D);
      Ans = max(Ans, N->Val);
//      printf("%lld [%u, %u]\n", N->Val, N->RgL, N->RgR);
      while (N->Lay >= m) A = N->RgL, B = N->RgR, N->Dec(1, D); 
//      printf("%lld [%u, %u]\n", N->Val, N->RgL, N->RgR);
    }
    printf("Case #%u: %lld\n", T, Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1
10 10 1
290062 1 10
297706 1 5
32775 1 1
3889 4 9
182275 1 1
123691 1 1
94644 1 7
257710 1 3
115393 1 6
205793 5 5
*/
