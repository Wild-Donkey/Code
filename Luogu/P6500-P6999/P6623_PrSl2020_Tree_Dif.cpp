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
//unsigned Tmp(0);
unsigned long long Ans;
char Pool[2100000], *a[21];
struct Tree {
  vector <Tree*> Son;
  unsigned Dep, Val;
  inline unsigned DFS() {
//    printf("DFS %u\n", this);
    unsigned TmpC(0);
    for (unsigned i(0), j(1); i < 21; ++i, j <<= 1) TmpC ^= ((unsigned)a[i][Dep & (j - 1)] << i);
    for (auto i:Son) i->Dep = Dep + 1, TmpC ^= i->DFS();
    for (unsigned i(0), j(1); i < 21; ++i, j <<= 1) TmpC ^= ((unsigned)a[i][Dep & (j - 1)] << i);
    for (unsigned i(0), j(1); i < 21; ++i, j <<= 1) {
      unsigned Ned(j - (Val & (j - 1)));
      if(Ned <= Dep) a[i][(Dep - Ned) & (j - 1)] ^= 1;
    }
//    printf("%u Contri %u\n", this, TmpC);
    Ans += (TmpC ^= Val);
    return TmpC;
  }
}T[525050];
unsigned m, n;
unsigned A, B, C, D, t;
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), a[20] = Pool;
  for (unsigned i(20); i; --i) a[i - 1] = a[i] + (1 << i);
//  for (unsigned i(0); i < 21; ++i) printf("%u ", a[i] - Pool); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) T[i].Val = RD();
  for (unsigned i(2); i <= n; ++i) T[RD()].Son.push_back(T + i);
  T[1].DFS();
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

