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
const unsigned long long Mod(998244353);
unsigned long long Bin[200005], Fac[200005], Inv[200005];
unsigned long long Ans(0), Tmp(0);
unsigned m, n;
unsigned A(Mod - 2), B, t;
unsigned Cnt(0);
struct Node {
  vector<Node*> E;
  Node* Fa[20];
  unsigned Dep;
  inline void DFS() {
    for (auto i:E) if(i != Fa[0]){
      i->Fa[0] = this, i->Dep = Dep + 1;
      for (unsigned j(0); i->Fa[j]; ++j) i->Fa[j + 1] = i->Fa[j]->Fa[j];
      i->DFS();
    }
  }
}N[200005], * JuA, * JuB;
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Bin[0] = Fac[0] = Inv[n] = 1;
  for (unsigned i(1); i <= n; ++i) {Bin[i] = Bin[i - 1] << 1; if(Bin[i] >= Mod) Bin[i] -= Mod;}
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Tmp = Fac[n]; while (A) {if(A & 1) Inv[n] = Inv[n] * Tmp % Mod; Tmp = Tmp * Tmp % Mod, A >>= 1;}
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  A = Mod - 2, Tmp = Bin[n], Bin[n] = 1;
  while (A) {if(A & 1) Bin[n] = Bin[n] * Tmp % Mod; Tmp = Tmp * Tmp % Mod, A >>= 1;}
  for (unsigned i(n - 1); ~i; --i) {Bin[i] = Bin[i + 1] << 1; if(Bin[i] >= Mod) Bin[i] -= Mod;}
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].E.push_back(N + B);
    N[B].E.push_back(N + A);
  }
  N[1].DFS(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    JuA = N + RD(), JuB = N + RD();
    if(JuA->Dep < JuB->Dep) swap(JuA, JuB);
    A = JuA->Dep, B = JuB->Dep;
    for (unsigned i(18); ~i; --i) if((JuA->Fa[i]) && (JuA->Fa[i]->Dep >= B)) JuA = JuA->Fa[i];
    if(JuA != JuB) {
      for (unsigned i(18); ~i; --i) if(JuA->Fa[i] != JuB->Fa[i]) JuA = JuA->Fa[i], JuB = JuB->Fa[i];
      JuA = JuA->Fa[0], JuB = JuB->Fa[0];
    }
    A -= JuA->Dep, B -= JuA->Dep, Ans = 0, Tmp = Fac[A] * Fac[B] % Mod;
    for (unsigned i(0); i <= B; ++i) {
      Ans = (Ans + (((Tmp * Inv[i] % Mod) * Inv[i] % Mod) * Inv[A - i] % Mod) * Inv[B - i]) % Mod;
    }
    printf("%llu\n", Ans * Bin[A + B] % Mod);
  }
//  }
  return Wild_Donkey;
}

