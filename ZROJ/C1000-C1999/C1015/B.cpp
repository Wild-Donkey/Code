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
unsigned a[10005], m, n, VN, MN, SN;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned long long Ans(0);
bitset<2000005> ColumMi, ColumSi, Vert;
struct Node {
  Node* LS, * RS;
  unsigned Val;
  inline void Chg(unsigned L, unsigned R) {
    ++Val;
    if(L == R) return;
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Chg(L, Mid); 
    else RS->Chg(Mid + 1, R);
  }
  inline void Qry(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Ans += Val;return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Qry(L, Mid); 
    if(B > Mid) RS->Qry(Mid + 1, R);
  }
}NP[4000005], * N1, * N2, * CntN(NP);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Val = 0;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  VN = ((n = RD()) << 1) - 1, m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    Vert[A + B - 1] = 1;
    if((A + B) & 1) ColumSi[(n + A - B + 1) >> 1] = 1;
    else ColumMi[(n + A - B + 1) >> 1] = 1;
  }
  Build(N1 = ++CntN, 1, MN = (((n + 1) >> 1) << 1) - 1);
  Build(N2 = ++CntN, 1, SN = ((n >> 1) << 1));
  for (unsigned i(1); i <= MN; ++i) if(!ColumMi[i]) A = i, N1->Chg(1, MN);
  for (unsigned i(1); i <= SN; ++i) if(!ColumSi[i]) A = i, N2->Chg(1, SN);
  for (unsigned i(1); i <= VN; ++i) {
    if(!Vert[i]) {
      unsigned Rr((i <= n) ? (i >> 1) : ((VN - i + 1) >> 1));
      if(i & 1) {
        A = (MN >> 1) + 1 - Rr, B = (MN >> 1) + 1 + Rr, N1->Qry(1, MN);
      } else {
        A = (SN >> 1) - Rr + 1, B = (SN >> 1) + Rr, N2->Qry(1, SN); 
      }
    }
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
4 2
1 2
4 2
*/
