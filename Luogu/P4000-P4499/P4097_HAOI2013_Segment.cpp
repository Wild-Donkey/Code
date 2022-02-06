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
const double Ep(0.0000000001);
const unsigned Mod(39989), Inf(1000000000);
double Now(0);
unsigned A, B, Ans(0);
inline char Eq(double x, double y) { return (x + Ep >= y) && (y + Ep >= x); }
struct Seg {
  double K;
  unsigned Lx, Ly, Rx, Ry;
  inline void In() {
    Lx = ((RD() + Ans - 1) % Mod) + 1, Ly = ((RD() + Ans - 1) % Inf) + 1;
    Rx = ((RD() + Ans - 1) % Mod) + 1, Ry = ((RD() + Ans - 1) % Inf) + 1;
    if (Lx > Rx) swap(Lx, Rx), swap(Ly, Ry);
    K = ((double)Ry - Ly) / (Rx - Lx);
  }
  inline double Get(unsigned x) {
    if (Rx == Lx) return max(Ly, Ry);
    return Ly + ((((double)Ry - Ly)) * (x - Lx) / (Rx - Lx));
  }
}S[100005], * Best;
struct Node {
  Seg* Mx;
  Node* LS, * RS;
  inline void Insert(unsigned L, unsigned R, Seg* Cur) {
    if (L == R) {
      if (Mx > S + 100000) { Mx = Cur; return; }
      double CM(Cur->Get(L)), XM(Mx->Get(L));
      if (Eq(CM, XM)) { Mx = min(Mx, Cur); return; }
      if (CM > XM) Mx = Cur; return;
    }
    unsigned Mid((L + R) >> 1);
    if ((A <= L) && (R <= B)) {
      if (Mx > S + 100000) { Mx = Cur; return; }
      double CM(Cur->Get(Mid)), XM(Mx->Get(Mid));
      if (Eq(CM, XM)) {
        if (Eq(Cur->K, Mx->K)) { Mx = min(Mx, Cur); return; }
        if (Cur < Mx) {
          if (Cur->K > Mx->K) LS->Insert(L, Mid, Mx);
          else RS->Insert(Mid + 1, R, Mx);
        }
        else {
          if (Cur->K > Mx->K) RS->Insert(Mid + 1, R, Cur);
          else LS->Insert(L, Mid, Cur);
        }
        Mx = min(Mx, Cur);
        return;
      }
      if (CM > XM) {
        if ((Cur->Get(L) + Ep > Mx->Get(L)) && (Cur->Get(R) + Ep > Mx->Get(R))) { Mx = Cur;return; }
        if (Cur->K > Mx->K) LS->Insert(L, Mid, Mx);
        else RS->Insert(Mid + 1, R, Mx);
        Mx = Cur;return;
      }
      if ((Mx->Get(L) + Ep > Cur->Get(L)) && (Mx->Get(R) + Ep > Cur->Get(R))) return;
      if (Cur->K > Mx->K) return RS->Insert(Mid + 1, R, Cur);
      else return LS->Insert(L, Mid, Cur);
    }
    if (A <= Mid) LS->Insert(L, Mid, Cur);
    if (Mid < B) RS->Insert(Mid + 1, R, Cur);
  }
  inline void Qry(unsigned L, unsigned R) {
    double Tmp((Mx <= S + 100000) ? Mx->Get(A) : -1);
    if (Eq(Tmp, Now)) Best = min(Best, Mx);
    else if (Tmp > Now) Best = Mx, Now = Tmp;
    if (L == R) return;
    unsigned Mid((L + R) >> 1);
    if (A <= Mid) LS->Qry(L, Mid);
    else RS->Qry(Mid + 1, R);
  }
}N[80000], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Mx = S + 2000000;
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
unsigned m, n, Cnt(0);
signed main() {
  n = RD(), Build(N, 1, Mod);
  for (unsigned i(1); i <= n; ++i)
    if (RD()) S[++Cnt].In(), A = S[Cnt].Lx, B = S[Cnt].Rx, N->Insert(1, Mod, S + Cnt);
    else A = ((RD() + Ans - 1) % Mod) + 1, Best = NULL, Now = 0, N->Qry(1, Mod), Ans = Best - S, printf("%u\n", Ans = ((Ans > 0x3f3f3f3f) ? 0 : Ans));
  return Wild_Donkey;
}