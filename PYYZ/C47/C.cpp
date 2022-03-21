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
#define Full 0xffffffffffffffff
#define Lbt(x) ((x)&((~(x))+1))
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
struct Line {
  vector<Line*> E;
  char Fr, To, Col;
}a[30];
unsigned long long Ava[60], Used(Full);
unsigned Pre[30], List[60], Lef(0), Ri(0), m, n, nn;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void Clr() {
  for (unsigned i(0); i < m; ++i) a[i].E.clear(), a[i].Col = 0;
  memset(Pre, 0, sizeof(Pre));
  memset(Ava, 0xff, sizeof(Ava));
  nn = ((n = RD()) << 1), m = RD(), Used = Full, Lef = Ri = Cnt = 0;
}
inline void No (const unsigned& x, const unsigned& y) {Ava[x] &= Full ^ (1 << y), Ava[y] &= Full ^ (1 << x);}
inline void DFS(Line* x) {
  printf("DFS %u\n", x - a);
  for (auto i:x->E) {
    if (i->Col == x->Col) {Flg = 1;return;}
    if (i->Col) continue;
    i->Col = (x->Col ^ 3), DFS(i);
    if(Flg) return;
  }
}
inline char Solve(unsigned x) {
  printf("%u\n", x);
  if(x > Cnt) return 1;
  unsigned Cur(List[x]);
  if(!((Used >> Cur) & 1)) return Solve(x + 1);
  Used ^= (1 << Cur);
  for (unsigned i(Ava[x]), j(0); i && j <= nn; i >>= 1, ++j) if((i & 1) && (j) && ((Used >> j) & 1)) {
    A = j, B = List[x]; if(A > B) swap(A, B);
    if(((Pre[A] ^ Pre[B]) & Lef) && ((Pre[A] ^ Pre[B]) & Ri)) {No(A, B); continue;}
    printf("Try [%u, %u]\n", A, B);
    for (unsigned k(A); k < B; ++k) Pre[k] ^= (1 << m);
    if (!((Pre[A] ^ Pre[B]) & Ri)) {
      Ri &= (1 << (m));
      ++m;
      if(Solve(x + 1)) return 1;
      --m;
      Ri ^= (1 << (--m));
    }
    if (!((Pre[A] ^ Pre[B]) & Lef)) {
      Lef &= (1 << (m));
      ++m;
      if(Solve(x + 1)) return 1;
      --m;
      Lef ^= (1 << (--m));
    }
    for (unsigned k(A); k < B; ++k) Pre[k] ^= (1 << m);
  }
  return 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(0); i < m; ++i) Pre[a[i].Fr = RD()] ^= (1 << i), Pre[a[i].To = RD()] ^= (1 << i);
    for (unsigned i(1); i <= nn; ++i) {if(!Pre[i]) List[++Cnt] = i; Pre[i] ^= Pre[i - 1]; }
    for (unsigned i(0); i < m; ++i) Used ^= (1 << a[i].Fr), Used ^= (1 << a[i].To);
    for (unsigned i(0); i < m; ++i) for (unsigned j(0); j < m; ++j) if((a[i].Fr < a[j].Fr) && (a[i].To < a[j].To))
      a[i].E.push_back(a + j), a[j].E.push_back(a + i);
    for (unsigned i(0); i < m; ++i) if(!(a[i].Col)) {
      a[i].Col = 1, DFS(a + i);
      if(Flg) break;
    }
    if(Flg) {printf("Dissatisfied\n");continue;}
    for (unsigned i(0); i < m; ++i) if(a[i].Col == 1) Lef &= (1 << i); else Ri &= (1 << i);
    for (unsigned i(0); i < m; ++i) for (unsigned j(0); j < m; ++j) if((a[i].Col ^ a[j].Col) && (a[i].Fr < a[j].Fr)) {
      if(a[i].To < a[j].Fr)  {
        for (unsigned k(a[i].Fr + 1); k < a[i].To; ++k) for (unsigned l(a[j].Fr + 1); l < a[j].To; ++l) No(k, l);
        continue;
      }
      if(a[i].To > a[j].To) {
        for (unsigned k(1); k < a[i].Fr; ++k) for (unsigned l(a[j].Fr + 1); l < a[j].To; ++l) No(k, l);
        for (unsigned k(a[i].To + 1); k <= nn; ++k) for (unsigned l(a[j].Fr + 1); l < a[j].To; ++l) No(k, l);
        continue;
      }
      for (unsigned k(1); k < a[i].Fr; ++k) for (unsigned l(a[j].Fr + 1); l < a[i].To; ++l) No(k, l);
      for (unsigned k(a[j].To + 1); k <= nn; ++k) for (unsigned l(a[j].Fr + 1); l < a[i].To; ++l) No(k, l);
      for (unsigned k(a[i].Fr + 1); k < a[j].Fr; ++k) for (unsigned l(a[i].To + 1); l < a[i].To; ++l) No(k, l);
    }
    printf(Solve(1) ? "Satisfied\n" : "Dissatisfied\n");
  }
  return Wild_Donkey;
}
/*
2
3
2
1 4
2 5

*/
