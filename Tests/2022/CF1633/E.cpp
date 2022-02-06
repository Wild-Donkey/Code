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
struct Edge {
  unsigned Fr, To, Val;
  const inline char operator < (const Edge& x) const { return Val < x.Val; }
}E[305], * L, * R;
struct Ans {
  long long Val;
  unsigned Pos, LC, RC;
}A[46005];
set<unsigned> S;
long long Prt(0);
unsigned Now, m, n, p, k, mod, mul, pls, Q;
unsigned Fa[55], Stack[55], STop(0), Cnt(0);
inline unsigned Find(unsigned x) {
  while (x ^ Fa[x]) Stack[++STop] = x, x = Fa[x];
  while (STop) Fa[Stack[STop--]] = x;
  return x;
}
inline Edge* Get() {
  if ((L > E) && (R <= E + m)) return ((Now - L->Val) < (R->Val - Now)) ? (L--) : (R++);
  if (L > E) return L--;
  return R++;
}
inline void Kruskal() {
  for (unsigned i(n + 1); i; --i) Fa[i] = i;
  long long Sum(0);
  unsigned Add(0), AddL(0), AddR(0);
  L = E;
  while ((L < E + m) && ((L + 1)->Val <= Now)) ++L;
  R = L + 1;
  while (Add < n) {
    Edge* Cur(Get());
    // printf("Now %u Get %u\n", Now, Cur->Val);
    if (Find(Cur->Fr) != Find(Cur->To)) {
      Fa[Fa[Cur->Fr]] = Fa[Cur->To], ++Add;
      if (Cur->Val <= Now) ++AddL, Sum += Now - Cur->Val; else ++AddR, Sum += Cur->Val - Now;
    }
  }
  A[++Cnt] = Ans{ Sum, Now, AddL, AddR };
}
inline void Qry(unsigned x) {
  // printf("Answer %u\n", x);
  unsigned BL(1), BR(Cnt);
  while (BL ^ BR) {
    unsigned Mid((BL + BR + 1) >> 1);
    if (A[Mid].Pos > x) BR = Mid - 1;
    else BL = Mid;
  }
  // printf("Do %u Ans = %llu Pos %u LC %u RC %u\n", L, A[L].Val, A[L].Pos, A[L].LC, A[L].RC);
  Prt ^= (A[BL].Val + ((long long)A[BL].LC - A[BL].RC) * (x - A[BL].Pos));
  // printf("Ans %llu\n", (A[L].Val + ((long long)A[L].LC - A[L].RC) * (x - A[L].Pos)));
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD() - 1, m = RD();
  for (unsigned i(1); i <= m; ++i) E[i].Fr = RD(), E[i].To = RD(), E[i].Val = RD();
  sort(E + 1, E + m + 1);
  for (unsigned i(1); i <= m; ++i) S.insert(E[i].Val);
  for (unsigned i(1); i < m; ++i) for (unsigned j(i + 1); j <= m; ++j)
    if (E[i].Val ^ E[j].Val) S.insert(((E[i].Val + E[j].Val) >> 1) + 1);
  S.insert(0), S.insert(100000000);
  for (auto i : S) Now = i, Kruskal();
  p = RD(), k = RD(), mul = RD(), pls = RD(), mod = RD();
  for (unsigned i(1); i <= p; ++i) Qry(Q = RD());
  for (unsigned i(p + 1); i <= k; ++i) Qry(Q = ((unsigned long long)Q * mul + pls) % mod);
  printf("%llu\n", Prt);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
5 8
4 1 4
3 1 0
3 5 3
2 5 4
3 4 8
4 3 4
4 2 8
5 3 9
3 11 1 1 10
0 1 2
*/