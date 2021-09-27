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
inline int RD() {
  int intmp(0);
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
int a[10005], m, n;
int A, B, C, D, t;
int Cnt(0), Tmp(0);
int L(0x3f3f3f3f), R(0);
char Ans[10005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (int T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (int i(1); i <= n; ++i) a[RD()] = i;
  for (int i(1); i <= n; ++i) {
    L = min(L, a[i]), R = max(R, a[i]);
    if(R - L == i - 1) Ans[i] = '1';
    else Ans[i] = '0';
  }
  printf("%s\n", Ans + 1);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

