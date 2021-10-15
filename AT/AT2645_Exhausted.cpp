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
#define LE 1
#define RE m
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
pair<unsigned, unsigned> a[200005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Val, Tag;
  inline void PsDw() {
    if(Tag) {
      LS->Tag += Tag;
      RS->Tag += Tag;
      LS->Val += Tag;
      RS->Val += Tag; 
      Tag = 0;
    }
  }
  inline void Change(unsigned L, unsigned R) {
    if(A <= L) {++Val, ++Tag; return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    if(A <= Mid) LS->Change(L, Mid);
    RS->Change(Mid + 1, R);
    Val = max(LS->Val, RS->Val);
  }
  inline void Qry(unsigned L, unsigned R) {
    if(R <= A) {C = max(Val, C); return;}
    unsigned Mid((L + R) >> 1);
    PsDw();
    LS->Qry(L, Mid);
    if(A > Mid) RS->Qry(Mid + 1, R);
  }
}N[400005], * CntN(N);
inline void Build (Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Val = m - L; return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Val = max(x->LS->Val, x->RS->Val);
}
signed main() {
  n = RD(), m = RD(), Build(N, LE, RE);
  Ans = max(n + m, m << 1);
  for (unsigned i(1); i <= n; ++i) a[i].second = RD() + 1, a[i].first = RD() - 1;
  sort(a + 1, a + n + 1);
  for (unsigned i(n); i; --i) {
    if(a[i].second <= m) A = a[i].second, N->Change(LE, RE);
    if(a[i].first ^ a[i - 1].first) {
      A = a[i].first, C = 0, N->Qry(LE, RE);
      Ans = max(Ans, C + a[i].first + 1);
    }
  }
  printf("%u\n", Ans - (m << 1));
  return Wild_Donkey;
}

