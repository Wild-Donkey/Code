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
#define INF 0x3f3f3f3f3f3f3f3f
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
long long Ans(0), C, a[2000005];
unsigned m, n;
unsigned A, B, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  long long Mx, Val, Tag;
  inline void PsDw () {
    if(Val != INF) {
      LS->Mx = RS->Mx = LS->Val = RS->Val = Val + Tag;
      LS->Tag = RS->Tag = Tag = 0;
      Val = INF;
    } else {
      if(Tag) {
        LS->Mx += Tag, RS->Mx += Tag;
        LS->Tag += Tag, RS->Tag += Tag;
        Tag = 0;
      }
    }
  }
  inline void Chg (unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Tag = 0, Mx = Val = C;return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Chg(L, Mid);
    if(B > Mid) RS->Chg(Mid + 1, R);
    Mx = max(LS->Mx, RS->Mx);
  }
  inline void Inc (unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Mx += C, Tag += C;return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Inc(L, Mid);
    if(B > Mid) RS->Inc(Mid + 1, R);
    Mx = max(LS->Mx, RS->Mx);
  }
  inline void Qry (unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Ans = max(Ans, Mx);return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Qry(L, Mid);
    if(B > Mid) RS->Qry(Mid + 1, R);
  }
}N[2000005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Val = INF, x->Tag = 0;
  if(L == R) {x->Mx = x->Val = a[L]; return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Mx = max(x->LS->Mx, x->RS->Mx);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RDsg();
  Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    D = RD(), A = RD(), B = RD();
    if(D ^ 3) {
      C = RDsg();
      if(D ^ 1) N->Inc(1, n);
      else N->Chg(1, n);
    } else {
      Ans = -INF, N->Qry(1, n);
      printf("%lld\n", Ans);
    }
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}

