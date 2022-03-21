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
unsigned Inv[100005];
unsigned long long OpM, OpP, Ans;
unsigned m, n, A, B, C, D, E, F, t;
inline unsigned long long Udt(const unsigned& x) {unsigned Rt(((Mod - x) << 1) + 1); Mn(Rt); return Rt; }
struct Inner {
  unsigned LS, RS, Opt;
}I[41225005], *CntI(I), *Border(I);
inline void PsDw(Inner* x) {
//  printf("PsDw %u\n", x - I);
  unsigned long long Tmp(Udt(x->Opt));
  if(!(x->LS)) I[x->LS = ++CntI - I] = {0, 0, 0};
  I[x->LS].Opt = (I[x->LS].Opt * Tmp + x->Opt) % Mod;
  if(!(x->RS)) I[x->RS = ++CntI - I] = {0, 0, 0};
  I[x->RS].Opt = (I[x->RS].Opt * Tmp + x->Opt) % Mod;
  x->Opt = 0;
}
inline void Chg(Inner* x, unsigned L, unsigned R) {
//  printf("Chg %u [%u, %u] -> [%u, %u]\n", x - I, L, R, C, D);
  if((C <= L) && (R <= D)) {
    x->Opt = (x->Opt * OpM + OpP) % Mod;
    return;
  }
  PsDw(x);
  unsigned Mid((L + R) >> 1);
  if(C <= Mid) Chg(I + x->LS, L, Mid);
  if(D > Mid) Chg(I + x->RS, Mid + 1, R);
}
inline void Find(Inner* x, unsigned L, unsigned R) {
  if(!(x->LS)) {Ans = (Ans * Udt(x->Opt) + x->Opt) % Mod; return;}
  PsDw(x);
  unsigned Mid((L + R) >> 1);
  if(B <= Mid) Find(I + x->LS, L, Mid);
  else Find(I + x->RS, Mid + 1, R);
}
struct Node {
  unsigned LS, RS, My;
}N[200005], *CntN(N);
inline void Chg(Node*x, unsigned L, unsigned R) {
  if((A <= L) && (R <= B)) {Chg(I + x->My, 1, n);return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Chg(N + x->LS, L, Mid);
  if(B > Mid) Chg(N + x->RS, Mid + 1, R);
}
inline void Find(Node*x, unsigned L, unsigned R) {
  Find(I + x->My, 1, n);
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Find(N + x->LS, L, Mid);
  else Find(N + x->RS, Mid + 1, R);
}
inline void Build(Node* x, unsigned L, unsigned R) {
  I[x->My = ++CntI - I] = {0, 0, 0};
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(N + (x->LS = ++CntN - N), L, Mid);
  Build(N + (x->RS = ++CntN - N), Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
//  freopen("P3688_0.in", "r", stdin);
//  freopen("P3688.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Build(N, 0, n), Inv[1] = 1, *Border = {0, 0, 0};
  for (unsigned i(2); i <= n; ++i) Inv[i] = (Mod - (Mod / i)) * Inv[Mod % i] % Mod;
  for (unsigned i(1); i <= m; ++i) {
    t = RD(), A = RD(), B = RD();
    if(t & 1) {
      OpP = Inv[B - A + 1], OpM = Udt(OpP), E = A, F = B;
      if(F < n) A = E, B = F, C = F + 1, D = n, Chg(N, 1, n);
      if(E > 1) A = 1, B = E - 1, C = E, D = F, Chg(N, 1, n);
      C = A = E, D = B = F, OpP <<= 1, Mn(OpP), OpM = Udt(OpP), Chg(N, 1, n);
      OpP = (OpP * 499122177 % Mod) * (F - E) % Mod, OpM = Udt(OpP), C = E, D = F, Chg(Border, 1, n);
      OpP = 1, OpM = 998244352;
      if(E > 1) C = 1, D = E - 1, Chg(Border, 1, n);
      if(F < n) C = F + 1, D = n, Chg(Border, 1, n);
    }
    else {--A, Ans = 1; if(A) Find(N, 1, n); else Find(Border, 1, n); printf("%llu\n", Ans);}
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
