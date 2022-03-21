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
#define Mn(x) (x)-=(((x)>=Mod)?Mod:0)
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
const unsigned long long Mod(998244353); 
unsigned long long Inv[100005], Ans;
unsigned long long OpM, OpP;
unsigned m, n, A, B, C, D, E, F, t;
inline void UdtM() {OpM = ((Mod - OpP) << 1) + 1, Mn(OpM);}
struct Inner {
  Inner *LS, *RS; 
  unsigned long long Mul, Pls;
}I[10000005], *CntI(I), *Border(I);
inline void PsDw(Inner* x) {
//  printf("PsDw %u\n", x - I);
  if(!(x->LS)) *(x->LS = ++CntI) = {NULL, NULL, 1, 0};
  x->LS->Mul = x->LS->Mul * x->Mul % Mod;
  x->LS->Pls = (x->LS->Pls * x->Mul + x->Pls) % Mod;
  if(!(x->RS)) *(x->RS = ++CntI) = {NULL, NULL, 1, 0};
  x->RS->Mul = x->RS->Mul * x->Mul % Mod;
  x->RS->Pls = (x->RS->Pls * x->Mul + x->Pls) % Mod;
  x->Mul = 1, x->Pls = 0;
}
inline void Chg(Inner* x, unsigned L, unsigned R) {
//  printf("Chg %u [%u, %u] -> [%u, %u]\n", x - I, L, R, C, D);
  if((C <= L) && (R <= D)) {
    x->Mul = x->Mul * OpM % Mod;
    x->Pls = (x->Pls * OpM + OpP) % Mod;
    return;
  }
  PsDw(x);
  unsigned Mid((L + R) >> 1);
  if(C <= Mid) Chg(x->LS, L, Mid);
  if(D > Mid) Chg(x->RS, Mid + 1, R);
}
inline void Find(Inner* x, unsigned L, unsigned R) {
  if(!(x->LS)) {Ans = (Ans * x->Mul + x->Pls) % Mod; return;}
  PsDw(x);
  unsigned Mid((L + R) >> 1);
  if(B <= Mid) Find(x->LS, L, Mid);
  else Find(x->RS, Mid + 1, R);
}
struct Node {
  Node *LS, *RS;
  Inner *My;
  inline void Chg(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {::Chg(My, 1, n);return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Chg(L, Mid);
    if(B > Mid) RS->Chg(Mid + 1, R);
  }
  inline void Find(unsigned L, unsigned R) {
    ::Find(My, 1, n);
    if(L == R) return;
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Find(L, Mid);
    else RS->Find(Mid + 1, R);
  }
}N[200005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  *(x->My = ++CntI) = {NULL, NULL, 1, 0};
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
  freopen("P3688_0.in", "r", stdin);
  freopen("P3688.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Build(N, 0, n), Inv[1] = 1, *Border = {NULL, NULL, 1, 0};
  for (unsigned i(2); i <= n; ++i) Inv[i] = (Mod - (Mod / i)) * Inv[Mod % i] % Mod;
  for (unsigned i(1); i <= m; ++i) {
    t = RD(), A = RD(), B = RD();
    if(t & 1) {
      OpP = Inv[B - A + 1], UdtM(), E = A, F = B;
      if(F < n) A = E, B = F, C = F + 1, D = n, N->Chg(1, n);
      if(E > 1) A = 1, B = E - 1, C = E, D = F, N->Chg(1, n);
      C = A = E, D = B = F, OpP <<= 1, Mn(OpP), UdtM(), N->Chg(1, n);
      OpP = (OpP * 499122177 % Mod) * (F - E) % Mod, UdtM(), C = E, D = F, Chg(Border, 1, n);
      OpP = 1, OpM = 998244352;
      if(E > 1) C = 1, D = E - 1, Chg(Border, 1, n);
      if(F < n) C = F + 1, D = n, Chg(Border, 1, n);
    }
    else {--A, Ans = 1; if(A) N->Find(1, n); else Find(Border, 1, n); printf("%llu\n", Ans);}
  }
//  }
  return Wild_Donkey;
}
//4abc - 2ab - 2ac - 2bc + a + b + c
/*
5 10
1 3 3
2 3 5
2 4 5
1 1 3
2 2 5
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
*/
