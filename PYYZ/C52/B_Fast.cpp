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
unsigned a[10005], l[10005], L[10005];
unsigned long long f[10005], N, D, Ans(0x3f3f3f3f3f3f3f3f);
unsigned m, n(0), C, t;
unsigned Cnt(0), Tmp(0);
struct Line {
  unsigned long long K, B;
  inline unsigned long long F(const unsigned long long y) const {return B + y * K;}
  inline const char Com (const Line &x, const unsigned long long y) const {
    return F(y) < x.F(y);
  }
}A;
struct Node {
  Node *LS, *RS;
  Line Val;
}T[100005], *CntT(T);
inline void Ins(Node* x, unsigned L, unsigned R) {
//  printf("insert %llux + %llu to [%u, %u] %llux + %llu\n", A.K, A.B, L, R, x->Val.K, x->Val.B);
  if(L == R) {if(A.Com(x->Val, L)) x->Val = A; return; }
  unsigned Mid((L + R) >> 1);
  if(A.Com(x->Val, Mid)) swap(x->Val, A);
  if(A.K > x->Val.K) {
    if(!(x->LS)) x->LS = ++CntT, x->LS->Val = x->Val, x->LS->LS = x->LS->RS = NULL;
    Ins(x->LS, L, Mid);
  } else {
    if(!x->RS) x->RS = ++CntT, x->RS->Val = x->Val, x->RS->LS = x->RS->RS = NULL;
    Ins(x->RS, Mid + 1, R);
  }
  return;
}
inline void Find(Node* x, unsigned L, unsigned R) {
  D = min(D, x->Val.F(C));
//  printf("%u Found %llu at [%u, %u]\n", C, D, L, R);
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(C <= Mid) {if(x->LS) Find(x->LS, L, Mid);}
  else {if(x->RS) Find(x->RS, Mid + 1, R);}
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
//  double Cu;
//  A = 1000000000;
//  for (unsigned i(1); i <= 500000; ++i) 
//    A = A * ((500000.00 - i) / 500000.000), printf("%u:%u ", i, A); putchar(0x0A);
  D = RD(), m = min((unsigned)20, RD()), N = 0;
  for (unsigned i(1); i <= D; ++i)
    if((C = RD()) > N) N = a[++n] = C, l[n] = 1;
    else ++l[n];
  for (unsigned i(n); i; --i) L[i] = L[i + 1] + l[i];
  memset(f, 0x3f, ((n + 1) << 3)), f[0] = 0, Ans = 0x3f3f3f3f3f3f3f3f;
  for (unsigned i(1); i <= m; ++i) {
    T->LS = T->RS = NULL, CntT = T, T->Val = {0, 0x3f3f3f3f3f3f3f3f};
    for (unsigned j(1); j <= n; ++j) A = {L[j], f[j - 1]}, Ins(T, 1, N);
//    f[0] = 0x3f3f3f3f3f3f3f3f;
    for (unsigned j(1); j <= n; ++j) C = a[j], D = 0x3f3f3f3f3f3f3f3f, Find(T, 1, N), f[j] = min(D, f[j]);
//    for (unsigned j(1); j <= n; ++j) printf("%llu ", f[j]); putchar(0x0A);
    Ans = min(f[n], Ans);
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

