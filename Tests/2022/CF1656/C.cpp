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
unsigned a[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void Clr() {
  n = RD(), Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {a[i] = RD(); if(a[i] == 1) Flg = 1;}
    if(!Flg) {printf("YES\n");continue;}
    Flg = 0;
    for (unsigned i(1); i < n; ++i) if(!a[i]) {Flg = 1;break;}
    if(Flg){printf("NO\n");continue;}
    Flg = 0, sort(a + 1, a + n + 1);
    for (unsigned i(1); i < n; ++i) if(a[i + 1] == a[i] + 1) {Flg = 1;break;}
    printf(Flg ? "NO\n" : "YES");
  }
  return Wild_Donkey;
}

