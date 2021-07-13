#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned MOD(1000000007);
unsigned Pow[500005], m, n, Base, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
unsigned Calc(unsigned x) {
  while () {
    
  }
  return ;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), k = RD();
  i
  for (register unsigned i(1); i <= n; ++i) {
    Pow[i] = Pow[i - 1] * (k + 1) % MOD;
  }
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    if() {
      
    }
  }
//  }
  return Wild_Donkey;
}
/*
10 ^ 0 = 10
10 ^ 1 = 11
10 ^ 2 = 8
10 ^ 3 = 9
10 ^ 4 = 14
10 ^ 5 = 15
10 ^ 6 = 12
10 ^ 7 = 13
10 ^ 8 = 2
10 ^ 9 = 3
10 ^ 10 = 0
10 ^ 11 = 1
10 ^ 12 = 6
*/
