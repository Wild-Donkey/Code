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
#define foreplay for
#define wild while
using namespace std;
const unsigned long long Mod(1000000007);
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
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned Mned(unsigned x) { return x - ((x >= Mod) ? Mod : 0); }
inline unsigned long long Mned(unsigned long long x) {
  return x - ((x >= Mod) ? Mod : 0);
}
unsigned a[50005], m, n, q;
unsigned A, B, C, D;
unsigned long long QAns(0), Ans[100005];
unsigned Cnt(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, His, Sum, Time, Len;
  unsigned Del, DHis, DSqHis;
  inline void Modi(unsigned long long D_, unsigned long long DHis_,
                   unsigned long long DSqHis_, unsigned Time_) {
    if (Time_ == Time) return;
    unsigned long long Diff(Time_ - Time), DelDi(Del * Diff % Mod);
    if (!DSqHis_) {
      His = (His + Val * Diff) % Mod;
      DSqHis = (DSqHis + DelDi * Del) % Mod;
      Mn(DHis += DelDi);
    } else {
      unsigned long long DSq_(D_ * D_ % Mod);
      His = (His + Val * Diff + DSqHis_ * Len) % Mod;
      His = (His + ((DHis_ * Sum) << 1)) % Mod;
      DSqHis = (DSqHis + DelDi * Del + DSqHis_) % Mod;
      DSqHis = (DSqHis + ((DHis_ * Del) << 1)) % Mod;
      Mn(DHis += DelDi), Mn(DHis += DHis_);
      Val = (Val + (D_ << 1) * Sum) % Mod;
      Val = (Val + DSq_ * Len) % Mod;
      Sum = (Sum + Len * D_) % Mod;
      Mn(Del += D_);
    }
    Time = Time_;
  }
  inline void PsDw() {
    LS->Modi(Del, DHis, DSqHis, Time);
    RS->Modi(Del, DHis, DSqHis, Time);
    Del = DHis = DSqHis = 0;
  }
  inline void Udt() {
    Time = LS->Time;
    Mn(Val = LS->Val + RS->Val);
    Mn(Sum = LS->Sum + RS->Sum);
    Mn(His = LS->His + RS->His);
  }
  inline void Build(unsigned L, unsigned R);
  inline void Pls(unsigned L, unsigned R) {
    if (A <= L && R <= B) {
      unsigned long long Diff(D - Time);
      Modi(C, C * Diff % Mod, (C * Diff % Mod) * C % Mod, D);
      return;
    }
    unsigned Mid((L + R) >> 1);
    PsDw();
    if (A <= Mid)
      LS->Pls(L, Mid);
    else
      LS->Modi(0, 0, 0, D);
    if (B > Mid)
      RS->Pls(Mid + 1, R);
    else
      RS->Modi(0, 0, 0, D);
    Udt();
  }
  inline void Qry(unsigned L, unsigned R) {
    if (A <= L && R <= B) {
      Mn(QAns += His);
      return;
    }
    unsigned Mid((L + R) >> 1);
    PsDw();
    if (A <= Mid) LS->Qry(L, Mid);
    if (B > Mid) RS->Qry(Mid + 1, R);
  }
} N[100005], *CntN(N);
inline void Node::Build(unsigned L, unsigned R) {
  // printf("[%u, %u] %u\n", L, R, this - N);
  Del = DHis = DSqHis = 0, Len = R - L + 1;
  if (L == R) {
    Sum = a[L], His = Val = (unsigned long long)Sum * Sum % Mod;
    return;
  }
  unsigned Mid((L + R) >> 1);
  (LS = (++CntN))->Build(L, Mid);
  (RS = (++CntN))->Build(Mid + 1, R);
  Udt();
}
struct Que {
  unsigned Time, L, R, Num;
  inline const char operator<(const Que &x) const { return Time < x.Time; }
} Q[100005], *CntQ(Q);
struct Modify {
  unsigned L, R, V;
} M[50005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), q = RD();
  for (unsigned i(1); i <= n; ++i) Mn(a[i] = RDsg() + (int)Mod);
  N->Build(1, n);
  for (unsigned i(1); i <= m; ++i)
    M[i].L = RD(), M[i].R = RD(), Mn(M[i].V = RDsg() + (int)Mod);
  for (unsigned i(0); i < q; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    if (C)
      *(++CntQ) = {C - 1, A, B, Cnt++};
    else
      Ans[Cnt++] = 0;
    *(++CntQ) = {D, A, B, Cnt++};
  }
  sort(Q + 1, CntQ + 1);
  for (unsigned i(1), j(1);; ++i) {
    while (Q[j].Time < i && (Q + j <= CntQ)) {
      QAns = 0, A = Q[j].L, B = Q[j].R;
      N->Qry(1, n);
      Ans[Q[j].Num] = QAns;
      ++j;
    }
    if (i > m) break;
    D = i, C = M[i].V, A = M[i].L, B = M[i].R;
    N->Pls(1, n);
  }
  for (unsigned i(0); i < q; ++i)
    printf("%llu\n", Mned(Ans[(i << 1) ^ 1] - Ans[i << 1] + Mod));
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
w += 1
z += 2k
y += x^2 + k^2
x += k

(a+x)^2 = y + za + wa^2
w = 1
z = 2x
y = x^2

(a + x + k)^2 = Δy + Δza + Δwa^2
a^2 + x^2 + k^2 + 2ax + 2ak + 2xk = Δy + Δza + Δwa^2

Δy = x^2 + k^2 + 2xk
Δz = 2x + 2k
Δw = 1

1 2 3
-1
1 1 100
1 1 100
1 1 0 0
1 1 0 1
1 1 0 2
*/