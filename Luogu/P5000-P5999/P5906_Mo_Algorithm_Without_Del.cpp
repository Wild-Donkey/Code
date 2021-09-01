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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned b[200005], a[200005], Fst[200005], Lst[200005];
unsigned* ValMx, m, n, Cnt(0), A, B, C, D, t, Ans[200005], Tmp(0);
unsigned BlcLen, STop(0);
struct Qry {
  unsigned L, R, Bel, Num;
  inline const char operator < (const Qry& x) const {
    return (this->Bel ^ x.Bel) ? (this->Bel < x.Bel) : (this->R < x.R);
  }
}Q[200005];
struct Stack {
  unsigned Pos, Val1, Val2, MxAns;
}S[1005];
void ClrA() {
  STop = 0;
  memset(Lst, 0, (n + 1) << 2);
  memset(Fst, 0, (n + 1) << 2);
}
unsigned ClrL() {
  register unsigned ClAns;
  while (STop) Fst[S[STop].Pos] = S[STop].Val1, Lst[S[STop].Pos] = S[STop].Val2, ClAns = S[--STop].MxAns;
  return ClAns;
}
signed main() {
  freopen("P5906_3.in", "r", stdin);
  freopen("P5906.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
  sort(b + 1, b + n + 1), ValMx = unique(b + 1, b + n + 1);
  for (register unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, ValMx, a[i]) - b;
  m = RD(), BlcLen = (n / sqrt(m)) + 1;
  for (register unsigned i(1); i <= m; ++i) Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i, Q[i].Bel = Q[i].L / BlcLen;
  sort(Q + 1, Q + m + 1);
  for (register unsigned i(1), NowL(1), NowR(0), NowAns(0), NowBack(BlcLen - 1); i <= m; ++i) {
    // printf("Now [%u, %u]\n", Q[i].L, Q[i].R);
    if (NowR < NowL) NowAns = 0, NowL = min(((Q[i].L / BlcLen) + 1) * BlcLen, Q[i].R + 1), NowR = NowL - 1;
    else {
      if (Q[i - 1].Bel ^ Q[i].Bel) ClrA(), NowL = min(((Q[i].L / BlcLen) + 1) * BlcLen, Q[i].R + 1), NowR = NowL - 1, NowAns = 0;
      else {
        NowL += STop, NowAns = ClrL();
        if (NowR < NowL) NowL = min(((Q[i].L / BlcLen) + 1) * BlcLen, Q[i].R + 1), NowR = NowL - 1;
      }
    }
    while (NowR < Q[i].R) {
      // printf("DoR [%u, %u] %u %u Ans %u\n", NowL, NowR, a[NowR + 1], Fst[a[NowR + 1]], NowAns);
      ++NowR, Lst[a[NowR]] = NowR;
      if (Fst[a[NowR]]) NowAns = max(NowAns, NowR - Fst[a[NowR]]);
      else Fst[a[NowR]] = NowR;
    }
    while (NowL > Q[i].L) {
      // printf("Do [%u, %u]\n", NowL, NowR);
      ++STop, --NowL, S[STop].Pos = a[NowL];
      S[STop].Val1 = Fst[a[NowL]], S[STop].Val2 = Lst[a[NowL]];
      Fst[a[NowL]] = NowL, S[STop].MxAns = NowAns;
      if (Lst[a[NowL]]) NowAns = max(NowAns, Lst[a[NowL]] - NowL);
      else Lst[a[NowL]] = NowL;
    }
    Ans[Q[i].Num] = NowAns;
  }
  for (register unsigned i(1); i <= m; ++i) printf("%u\n", Ans[i]);
  // system("pause");
  return Wild_Donkey;
}