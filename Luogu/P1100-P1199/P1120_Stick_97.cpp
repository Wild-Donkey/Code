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
#include <unordered_set>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
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
unsigned a[70], m, n, Mx(0), Sum(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
set<unsigned> Len;
void DFS(unsigned Dep, unsigned Fill) {
  if (Dep == B + 1) {
    Flg = 1;
    return;
  }
  if (Fill == 0) {
    for (unsigned i(Mx); i; --i)
      if (a[i]) {
        --a[i];
        if (i == A)
          DFS(Dep + 1, 0);
        else
          DFS(Dep, i);
        ++a[i];
        return;
      }
  }
  for (unsigned i(min(Mx, A - Fill)); i; --i)
    if (a[i]) {
      --a[i];
      if (Fill + i == A)
        DFS(Dep + 1, 0);
      else
        DFS(Dep, Fill + i);
      if (Flg) return;
      ++a[i];
    }
}
char Judge(unsigned x) {
  Flg = 0;
  A = x;
  B = Sum / x;
  DFS(1, 0);
  return Flg;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) Mx = max(A = RD(), Mx), Sum += A, ++a[A];
  for (unsigned i(sqrt(Sum)); i; --i)
    if (!(Sum % i)) Len.insert(i), Len.insert(Sum / i);
  for (auto i : Len)
    if (i >= Mx) {
      if (Judge(i)) {
        printf("%u\n", i);
        return 0;
      }
    }
  //  }
  //  system("pause");
  return Wild_Donkey;
}