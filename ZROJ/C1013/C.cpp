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
const unsigned long long Mod(1000000007);
unsigned long long Ans(1), Now(0);
unsigned Fa[805], Size[805], Stack[805], STop;
unsigned m, n, Cnt(0), List[640005];
unsigned A, B, C, D, t;
unsigned Tmp(0);
unsigned Plan[805][805];
vector<short> Have[805];
struct Edge {
  unsigned L, R, Val;
  const inline char operator < (Edge& x) const {return Val < x.Val;}
}E[805];
inline unsigned Find(unsigned x) {
  while (x ^ Fa[x]) Stack[++STop] = x, x = Fa[x];
  while (STop) Fa[Stack[STop--]] = x;
  return x;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = (n * (n - 1)) >> 1;
  for (unsigned i(1); i < n; ++i) E[i].L = RD(), E[i].R = RD(), E[i].Val = RD(); 
  sort(E + 1, E + n);
  for (unsigned i(1); i <= n; ++i) Fa[i] = i, Size[i] = 1, Have[i].push_back(i);
  for (unsigned i(1), j(1); i < n; ++i, ++j) {
//    printf("%u %u %u\n", i, j, Now);
    while (j < E[i].Val) {
      if(!Now) {printf("0\n");return 0;}
      Ans = Ans * (Now--) % Mod, List[++Cnt] = j++;
    }
    A = Find(E[i].L), B = Find(E[i].R);
    Fa[A] = B, Now += (Size[B] * Size[A]) - 1, Size[B] += Size[A];
  }
  for (unsigned i(E[n - 1].Val + 1); i <= m; ++i) {
    if(!Now) {printf("0\n");return 0;}
    Ans = Ans * (Now--) % Mod, List[++Cnt] = i;
  }
  printf("%u\n", Ans), Cnt = 0;
  for (unsigned i(1); i < n; ++i) Plan[E[i].L][E[i].R] = Plan[E[i].R][E[i].L] = E[i].Val;
  for (unsigned i(1); i <= n; ++i) Fa[i] = i, Size[i] = 1;
  for (unsigned i(1); i < n; ++i) {
    A = Find(E[i].L), B = Find(E[i].R);
//    printf("Link %u %u, Cnt %u\n", E[i].L, E[i].R, Cnt);
    if(Size[A] > Size[B]) swap(A, B);
    for (auto k:Have[A]) for (auto l:Have[B])
      if(!(((k == E[i].L) && (l == E[i].R)) || ((k == E[i].R) && (l == E[i].L))))
        Plan[k][l] = Plan[l][k] = List[++Cnt]; 
    for (auto k:Have[A]) Have[B].push_back(k);
    Size[B] += Size[A], Fa[A] = B;
  }
  for (unsigned i(1); i < n; ++i) for (unsigned j(i + 1); j <= n; ++j)
    if(!Plan[i][j]) Plan[i][j] = Plan[j][i] = List[++Cnt];
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) printf("%u ", Plan[i][j]);
    putchar(0x0A);
  }
//  }
  return Wild_Donkey;
}

