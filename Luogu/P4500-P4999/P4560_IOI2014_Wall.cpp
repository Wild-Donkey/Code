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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Mn, Mx;
  inline void PsDw() {
    if(Mn || (Mx ^ 0x3f3f3f3f)) {
//      printf("PsDw %u %u\n", Mn, Mx);
      LS->Mn = max(Mn, LS->Mn), LS->Mx = max(LS->Mx, LS->Mn);
      RS->Mn = max(Mn, RS->Mn), RS->Mx = max(RS->Mx, RS->Mn);
      LS->Mx = min(Mx, LS->Mx), LS->Mn = min(LS->Mn, LS->Mx);
      RS->Mx = min(Mx, RS->Mx), RS->Mn = min(RS->Mn, RS->Mx);
      Mn = 0, Mx = 0x3f3f3f3f;
    }
  }
  inline void Add (unsigned L, unsigned R){
    if((A <= L) && (R <= B)) {Mn = max(Mn, C), Mx = max(Mn, Mx); return;}
    PsDw();
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Add(L, Mid);
    if(B > Mid) RS->Add(Mid + 1, R);
  }
  inline void Rem (unsigned L, unsigned R){
//    printf("Rem [%u, %u] For [%u, %u]\n", L, R, A, B);
    if((A <= L) && (R <= B)) {Mx = min(Mx, C), Mn = min(Mx, Mn); return;}
    PsDw();
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Rem(L, Mid);
    if(B > Mid) RS->Rem(Mid + 1, R);
  }
  inline void Prt () {
    if(!LS) {printf("%u\n", Mn); return;}
    PsDw(), LS->Prt(), RS->Prt();
  }
}N[4000005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Mn = 0, x->Mx = 0x3f3f3f3f;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Build(N, 1, n); 
  for (unsigned i(1); i <= m; ++i) {
    D = RD(), A = RD() + 1, B = RD() + 1, C = RD();
    if(D & 1) N->Add(1, n);
    else N->Rem(1, n);
  }
  N->Prt(), putchar(0x0A);
//  }
//  system("pause");
  return Wild_Donkey;
}

