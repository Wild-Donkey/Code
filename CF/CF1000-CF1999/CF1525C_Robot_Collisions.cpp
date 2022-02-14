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
unsigned Ans[300005], m, n;
unsigned C, D, t;
unsigned Cnt(0), Tmp(0);
char IO[5];
struct Bot {
  Bot* Pre, * Nxt;
  unsigned Pos, Num;
  char Left;
  const inline char operator < (const Bot& x) const { return Pos < x.Pos; }
}A[300005], B[300005];
inline unsigned Calc(Bot* x, Bot* y) {
  if (x->Left && y->Left) return ((x->Pos + y->Pos) >> 1);
  if ((!x->Left) && y->Left) return ((y->Pos - x->Pos + 1) >> 1);
  if ((!x->Left) && (!(y->Left))) return (((m << 1) - x->Pos - y->Pos) >> 1);
  return (((m << 1) + x->Pos - y->Pos + 1) >> 1);
}
inline void Del(Bot* x) {
  if (x->Nxt) x->Nxt->Pre = x->Pre;
  if (x->Pre) x->Pre->Nxt = x->Nxt;
}
inline void Solve(Bot* x, Bot* y) { Ans[x->Num] = Ans[y->Num] = Calc(x, y), Del(x), Del(y); }
inline void Div(Bot* x, unsigned L) {
  sort(x + 1, x + L + 1);
  for (unsigned i(1); i <= L; ++i) x[i].Pre = x + i - 1, x[i].Nxt = x + i + 1;
  x[1].Pre = x[L].Nxt = NULL;
  Bot* Cur(x + 1), * New;
  while (Cur) {
    New = Cur->Nxt;
    if (Cur->Left) { if ((Cur->Pre) && (!(Cur->Pre->Left))) Solve(Cur->Pre, Cur); }
    else if ((Cur->Nxt) && (Cur->Nxt->Left)) New = New->Nxt, Solve(Cur, Cur->Nxt);
    Cur = New;
  }
  for (unsigned i(1); i <= L; ++i) if (!Ans[x[i].Num]) { Cur = x + i; break; }
  while (Cur && (Cur->Nxt) && (Cur->Left) && (Cur->Nxt->Left))
    New = Cur->Nxt->Nxt, Solve(Cur, Cur->Nxt), Cur = New;
  Cur = NULL;
  for (unsigned i(L); i; --i) if (!Ans[x[i].Num]) { Cur = x + i; break; }
  while (Cur && (Cur->Pre) && (!(Cur->Left)) && (!(Cur->Pre->Left)))
    New = Cur->Pre->Pre, Solve(Cur->Pre, Cur), Cur = New;
  Cur = NULL;
  for (unsigned i(L); i; --i) if (!Ans[x[i].Num]) { Cur = x + i; break; }
  if (Cur) {
    if (Cur->Pre) Solve(Cur->Pre, Cur);
    else Ans[Cur->Num] = 0xffffffff;
  }
}
inline void Clr() {
  n = RD(), m = RD(), C = D = 0;
  memset(Ans, 0, ((n + 1) << 2));
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) B[i].Pos = RD(), B[i].Num = i;
    for (unsigned i(1); i <= n; ++i) scanf("%s", IO), B[i].Left = ((IO[0] ^ 'L') ? 0 : 1);
    for (unsigned i(1); i <= n; ++i) {
      if ((B[i].Pos) & 1) B[++D] = B[i];
      else A[++C] = B[i];
    }
    Div(A, C), Div(B, D);
    for (unsigned i(1); i <= n; ++i) printf("%d ", Ans[i]);putchar(0x0A);
  }
  // system("pause");
  return Wild_Donkey;
}