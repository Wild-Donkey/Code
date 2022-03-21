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
unsigned long long Inv[100005], C, Ans, Tmp;
unsigned m, n, A, B, D, t;
struct Node {
  Node *LS, *RS; 
  unsigned long long Mul, Pls;
  inline void PsDw() {
    LS->Mul = LS->Mul * Mul % Mod;
    LS->Pls = (LS->Pls * Mul + Pls) % Mod;
    RS->Mul = RS->Mul * Mul % Mod;
    RS->Pls = (RS->Pls * Mul + Pls) % Mod;
    Mul = 1, Pls = 0;
  }
  inline void Chg(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {
      Mul = Mul * Tmp % Mod;
      Pls = (Pls * Tmp + C) % Mod;
      return;
    }
    PsDw();
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Chg(L, Mid);
    if(B > Mid) RS->Chg(Mid + 1, R);
  }
  inline void Find(unsigned L, unsigned R) {
    if(L == R){C = Pls; return;}
    PsDw();
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Find(L, Mid);
    else RS->Find(Mid + 1, R);
  }
}N[200005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Mul = 1, x->Pls = 0; return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
  freopen("P3688_0.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Build(N, 0, n), Inv[1] = 1;
  for (unsigned i(2); i <= n; ++i) Inv[i] = (Mod - (Mod / i)) * Inv[Mod % i] % Mod;
  for (unsigned i(1); i <= m; ++i) {
    D = RD(), A = RD(), B = RD();
    if(D & 1) C = Inv[B - A + 1], Tmp = ((Mod - C) << 1) + 1, Mn(Tmp), N->Chg(0, n);
    else {
      --A, C = 0, N->Find(0, n), A = B, Ans = Mod - C, C = 0, N->Find(0, n), C = Mod - C;
      printf("Done %llu %llu\n", C, Ans);
      printf("%llu\n", (C + Ans + ((Ans * C) << 1) + 1) % Mod);
    }
  }
//  }
  return Wild_Donkey;
}

