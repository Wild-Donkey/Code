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
unsigned E[35], m, n, N;
unsigned A, B, C, D, t;
unsigned Ans[605], Tmp(0);
//char Count[34000000];
inline unsigned Count (unsigned x) {
  unsigned TmpC(0);
  while (x) {x -= Lbt(x);++TmpC;}
  return TmpC;
}
inline void DFS (const unsigned Dep, const unsigned Cnt, const unsigned Now) {
  if(Dep == n) {++Ans[Cnt]; return;}
  DFS(Dep + 1, Cnt, Now);
  DFS(Dep + 1, Cnt + Count(Now & E[Dep]), Now | (1 << Dep));
}
signed main() {
//  freopen("ex_A2.in", "r", stdin);
//  freopen("A.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  N = (1 << (n = RD())), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD() - 1;
    B = RD() - 1;
    E[A] |= 1 << B;
    E[B] |= 1 << A;
  }
//  for (unsigned i(1); i < N; ++i) Count[i] = Count[i >> 1] + (i & 1);
  DFS(0, 0, 0);
  for (unsigned i(0); i <= m; ++i) printf("%u ", Ans[i]);
//  }
  return Wild_Donkey;
}

