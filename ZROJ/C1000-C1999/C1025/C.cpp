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
const unsigned long long Mod(2147483647);
unsigned long long Ans(0), a[200005], f[200005];
unsigned m, n, A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Gre, Red, Mx;
unsigned Q(unsigned x) {return x ^ (Ans % Mod);}
struct Node {
  Node* LS, * RS;
  unsigned Min;
  inline void Qry (unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) {C = min(C, Min); return;}
    unsigned Mid((L + R) >> 1);
    if ((A <= Mid) && (LS)) LS->Qry(L, Mid);
    if ((B > Mid) && (RS)) RS->Qry(Mid + 1, R);
  }
}N[10000005], *CntN(N);
inline void Chg (Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Min = B; return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) {
    if(!(x->LS)) x->LS = ++CntN;
    Chg(x->LS, L, Mid); 
  } else {
    if(!(x->RS)) x->RS = ++CntN;
    Chg(x->RS, Mid + 1, R);
  }
  x->Min = 0x3f3f3f3f;
  if(x->LS) x->Min = x->LS->Min;
  if(x->RS) x->Min = min(x->Min, x->RS->Min);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
  n = RD() + 1, Gre = RD(), Red = RD(), f[n] = 0, Mx = Gre + Red;
  for (unsigned i(1); i <= n; ++i) a[i] = a[i - 1] + RD();
  for (unsigned i(n - 1); i; --i) {
    C = 0x3f3f3f3f, A = (Gre + a[i]) % Mx;
    if(A <= Gre) B = A + Red - 1, N->Qry(0, Mx - 1);
    else B = Mx - 1, N->Qry(0, Mx - 1), A = 0, B = (Mx + a[i] - 1) % Mx, N->Qry(0, Mx - 1);
    if(C == 0x3f3f3f3f) f[i] = a[n] - a[i];
    else f[i] = f[C] + ((a[C] - a[i] + Mx - 1) / Mx) * Mx;
    A = a[i] % Mx, B = i, Chg(N, 0, Mx - 1);
//    printf("f[%u] %llu\n", i, f[i]);
  }
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    Ans = RD(), D = Ans % Mx, Ans -= D, C = 0x3f3f3f3f;
    A = (Mx + Gre - D) % Mx;
    if(A <= Gre) B = A + Red - 1, N->Qry(0, Mx - 1);
    else B = Mx - 1, N->Qry(0, Mx - 1), A = 0, B = Mx - D - 1, N->Qry(0, Mx - 1);
//    printf("Time %u To %u\n", D, C);
    if(C == 0x3f3f3f3f) Ans += a[n] + D;
    else Ans += f[C] + ((D + a[C] + Mx - 1) / Mx) * Mx;
    printf("%llu\n", Ans);
  }
//  }
  return Wild_Donkey;
}
/*
2 0
1 10
*/
