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
unsigned m, n, p, M;
unsigned A, B, C, D, t;
unsigned a[400005];
unsigned Cnt(0), Ans(0), Tmp(0), SCC(0), Top(0);
char Choice[400005], Flg(0);
struct Node;
struct Node {
  vector<Node*> To;
  unsigned DFSr, Low, Bel;
  char InS;
}N[1600005], * Stack[1600005], * Suf, * Pref;
struct Station {
  unsigned Le, Ri, Num;
  inline const char operator<(const Station& x) const{ return Num < x.Num;}
}S[400005];
inline char Cmpl(const Station &x, const Station &y) {return x.Le < y.Le;}
inline char Cmpr(const Station &x, const Station &y) {return x.Ri < y.Ri;}
inline void Tarjan(Node* x) {
  x->DFSr = x->Low = ++Cnt, Stack[++Top] = x, x->InS = 1; 
  for (auto i:x->To) {
    if(i->DFSr) { if(i->InS) x->Low = min(x->Low, i->Low); }
    else Tarjan(i), x->Low = min(x->Low, i->Low);
  }
  if(x->Low == x->DFSr) {
    ++SCC;
    do Stack[Top]->Bel = SCC, Stack[Top]->InS = 0;
    while (Stack[Top--] != x);
  }
}
signed main() {
  n = RD(), p = RD(), M = RD(), m = RD();
  Suf = N + (p << 1) + 1, Pref = Suf + p;
  for (unsigned i(1); i <= n; ++i)
    A = RD() << 1, B = RD() << 1, N[A ^ 1].To.push_back(N + B), N[B ^ 1].To.push_back(N + A);
  for (unsigned i(1); i <= p; ++i) S[i].Le = RD(), S[i].Ri = RD(), S[i].Num = i;
  for (unsigned i(1); i <= m; ++i)
    A = RD() << 1, B = RD() << 1, N[A].To.push_back(N + (B ^ 1)), N[B].To.push_back(N + (A ^ 1));
  sort(S + 1, S + p + 1, Cmpl);
  for (unsigned i(1); i <= p; ++i) Suf[i].To.push_back(N + ((S[i].Num << 1) ^ 1));
  for (unsigned i(1); i < p; ++i) Suf[i].To.push_back(Suf + i + 1);
  for (unsigned i(1); i <= p; ++i) a[i] = S[i].Le;
  for (unsigned i(1); i <= p; ++i) {
    A = upper_bound(a + 1, a + p + 1, S[i].Ri) - a;
    if(A <= p) N[S[i].Num << 1].To.push_back(Suf + A);
  }
  sort(S + 1, S + p + 1, Cmpr);
  for (unsigned i(1); i <= p; ++i) Pref[i].To.push_back(N + ((S[i].Num << 1) ^ 1));
  for (unsigned i(2); i <= p; ++i) Pref[i].To.push_back(Pref + i - 1);
  for (unsigned i(1); i <= p; ++i) a[i] = S[i].Ri;
  for (unsigned i(1); i <= p; ++i) {
    A = lower_bound(a + 1, a + p + 1, S[i].Le) - a - 1;
    if(A) N[S[i].Num << 1].To.push_back(Pref + A);
  }
  for (Node* i(N + ((p << 1) ^ 1)); i > N + 1; --i) if(!(i->DFSr)) Tarjan(i);
  for (unsigned i(1); i <= p; ++i)
    if(N[i << 1].Bel ^ N[(i << 1) ^ 1].Bel) Choice[i] = N[i << 1].Bel < N[(i << 1) ^ 1].Bel;
    else {Flg = 1; break;}
  if(Flg) {printf("-1\n"); return 0;}
  A = 0, B = 0x3f3f3f3f;
  sort(S + 1, S + p + 1);
  for (unsigned i(1); i <= p; ++i) if(Choice[i])
    A = max(A, S[i].Le), ++Ans;
  printf("%u %u\n", Ans, A);
  for (unsigned i(1); i <= p; ++i) if(Choice[i]) printf("%u ", i);
  return Wild_Donkey;
}

