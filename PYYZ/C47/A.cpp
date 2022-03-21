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
unsigned A(0), B(2000000000), C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg; 
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD() + 2000000000;
  while (A < B) {
    C = ((A + B) >> 1), D = a[1] - C + 1, Flg = 0;
    for (unsigned i(2); i <= n; ++i) {
      if((D > a[i]) && ((D - C) > a[i])) {Flg = 1; break;}
      D = max(D, a[i] - C) + 1;
    }
    if(Flg) A = C + 1;
    else B = C;
  }
  printf("%u\n", A);
//  }
  return Wild_Donkey;
}

