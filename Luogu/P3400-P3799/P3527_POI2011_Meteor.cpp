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
};
long long Tmp[300005];
int Act[600005][3];
unsigned Find[300005], Tim[600005];
unsigned Ans[300005], m, n, k;
unsigned A(0), B, C, D, t;
unsigned Cnt(0);
struct Station {
  long long Val;
  unsigned Pos, Bel;
  const inline char operator < (const Station& x) const { return Pos < x.Pos; }
}S[300005];
struct People {
  long long Ned, Now;
  unsigned Num;
}P[300005];
inline void Do(unsigned L, unsigned R, long long V, unsigned Sl, unsigned Sr) {
  // printf("Do [%u, %u] For %d\n", L, R, V);
  // printf("Sl %u Sr %u\n", S[Sl].Pos, S[Sr].Pos);
  if (R < S[Sl].Pos) return;
  if (L > S[Sr].Pos) return;
  unsigned Bl(Sl), Br(Sr), BMid;
  while (Bl ^ Br) {
    BMid = ((Bl + Br) >> 1);
    if (S[BMid].Pos >= L) Br = BMid;
    else Bl = BMid + 1;
  }
  Tmp[Bl] += V;
  // printf("[%u, ", Bl);
  Bl = Sl + 1, Br = Sr + 1;
  while (Bl ^ Br) {
    BMid = ((Bl + Br) >> 1);
    if (S[BMid].Pos > R) Br = BMid;
    else Bl = BMid + 1;
  }
  // printf("%u]\n", Bl);
  Tmp[Bl] -= V;
}
inline void Solve(unsigned Cur, unsigned L, unsigned R, unsigned Pl, unsigned Pr, unsigned Sl, unsigned Sr) {
  // printf("Now %u Solve [%u, %u] Peo [%u, %u] Sta [%u, %u]\n", Cur, L, R, Pl, Pr, Sl, Sr);
  if (L == R) { for (unsigned i(Pl); i <= Pr; ++i) Ans[P[i].Num] = Tim[L]; return; }
  if (Sl > Sr) { for (unsigned i(Pl); i <= Pr; ++i) Ans[P[i].Num] = 0x3f3f3f3f; return; }
  memset(Tmp + Sl - 1, 0, (Sr - Sl + 2) << 3);
  unsigned Mid((L + R) >> 1), STop(Pl), Top(Sr);
  while (Cur < Mid) ++Cur, Do(Act[Cur][0], Act[Cur][1], Act[Cur][2], Sl, Sr);
  while (Cur > Mid) Do(Act[Cur][0], Act[Cur][1], -Act[Cur][2], Sl, Sr), --Cur;
  for (unsigned i(Pl); i <= Pr; ++i) P[i].Now = 0;
  // for (unsigned i(Sl); i <= Sr; ++i) printf("%lld ", Tmp[i]); printf("Tmp\n");
  for (unsigned i(Sl); i <= Sr; ++i) {
    Tmp[i] += Tmp[i - 1], S[i].Val += Tmp[i], P[Find[S[i].Bel]].Now += S[i].Val;
    P[Find[S[i].Bel]].Now = min((long long)10000000000, P[Find[S[i].Bel]].Now);
  }
  // for (unsigned i(Sl); i <= Sr; ++i) printf("%lld ", S[i].Val); putchar(0x0A);
  // for (unsigned i(Pl); i <= Pr; ++i) printf("%u %lld %lld\n", P[i].Num, P[i].Now, P[i].Ned);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Find[i]); putchar(0x0A);
  for (unsigned i(Pl); i <= Pr; ++i) if (P[i].Now >= P[i].Ned) swap(P[STop], P[i]), swap(Find[P[STop++].Num], Find[P[i].Num]);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Find[i]); putchar(0x0A);
  // for (unsigned i(Pl); i <= Pr; ++i) printf("Done %u %lld %lld\n", P[i].Num, P[i].Now, P[i].Ned);
  // for (unsigned i(Sl); i <= Sr; ++i) printf("%u ", S[i].Bel); putchar(0x0A);
  for (unsigned i(Sr); i >= Sl; --i) if (Find[S[i].Bel] >= STop) swap(S[Top--], S[i]);
  // for (unsigned i(Sl); i <= Sr; ++i) printf("%u ", S[i].Bel); putchar(0x0A);
  sort(S + Sl, S + Top + 1);
  if (Pl < STop) Solve(Cur, L, Mid, Pl, STop - 1, Sl, Top);
  if (STop <= Pr) Solve(Cur, Mid + 1, R, STop, Pr, Top + 1, Sr);
}
//  inline void Clr() {}
signed main() {
  // freopen("P3527_48.in", "r", stdin);
  // freopen("P3527.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) S[i].Bel = RD(), S[i].Pos = i;
  for (unsigned i(1); i <= n; ++i) P[i].Ned = RD(), P[i].Num = Find[i] = i;
  k = RD();
  for (unsigned i(1); i <= k; ++i) {
    B = RD(), C = RD(), D = RD();
    if (B <= C) Act[++A][0] = B, Act[A][1] = C, Act[A][2] = D, Tim[A] = i;
    else {
      Act[++A][0] = 1, Act[A][1] = C, Act[A][2] = D, Tim[A] = i;
      Act[++A][0] = B, Act[A][1] = m, Act[A][2] = D, Tim[A] = i;
    }
  }
  Tim[A + 1] = 0x3f3f3f3f, Solve(0, 1, A + 1, 1, n, 1, m);
  for (unsigned i(1); i <= n; ++i) if (Ans[i] >= 0x3f3f3f3f) printf("NIE\n"); else printf("%u\n", Ans[i]);
  //  }
  // system("pause");
  return Wild_Donkey;
}